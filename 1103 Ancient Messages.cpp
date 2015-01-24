#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

struct Pos
{
    Pos(int r, int c)
        : r(r),
        c(c)
    {}
    
    int r, c;
};

const int UNKNOWN = 0;
int currentPos;

int counts[6];
char characters[6] = {'W', 'A', 'K', 'J', 'S', 'D'};
vector<vector<bool> > grid;
vector<vector<int> > positionValue;

const int NUM_SHIFTS = 8;
int rChange[NUM_SHIFTS] = {-1, -1, -1, 0, 0, 1, 1, 1};
int cChange[NUM_SHIFTS] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline bool InvalidPos(int r, int c)
{
    return r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size();
}



bool SpaceIsInner(int r, int c, const int &spaceValue, const int &shapeBeside)
{
    if (InvalidPos(r, c))
        return false;
    
    if (grid[r][c])
        return shapeBeside == positionValue[r][c];
    
    if (positionValue[r][c] != 0)
        return true;
    
    positionValue[r][c] = spaceValue;
    
    bool isInner = true;
    
    for (int i = 0; i < NUM_SHIFTS; ++i)
    {
        isInner &= SpaceIsInner(r + rChange[i], c + cChange[i], spaceValue, shapeBeside);
    }
    
    return isInner;
}

// Will also calculate how many spaces it has beside it
void ExpandShape(int r, int c, const int &shapeValue, vector<Pos> &allZeroSpaces)
{
    if (InvalidPos(r, c))
        return;
    
    if (grid[r][c] && positionValue[r][c] == 0)
    {
        positionValue[r][c] = shapeValue;
        
        for (int i = 0; i < NUM_SHIFTS; ++i)
            ExpandShape(r + rChange[i], c + cChange[i], shapeValue, allZeroSpaces);
    }
    else if (positionValue[r][c] == 0)
    {
        allZeroSpaces.push_back(Pos(r, c));
    }
}

void AddHexToGrid(const char &val, int r, int cStart)
{
    int v;
    if (val < 'a')
        v = val - '0';
    else
        v = val - 'a' + 10;
    
    if (v & (1 << 3))
        grid[r][cStart] = true;
    if (v & (1 << 2))
        grid[r][cStart + 1] = true;
    if (v & (1 << 1))
        grid[r][cStart + 2] = true;
    if (v & 1)
        grid[r][cStart + 3] = true;
}

void PrintAll(int i)
{
    while (counts[i]--)
        cout << characters[i];
}

int main()
{
    int rC, cC;
    
    vector<Pos> allSpaces;
    int T = 1;
    while (cin >> rC >> cC, rC)
    {
        currentPos = 0;
        grid.assign(rC, vector<bool>(cC * 4, false));
        positionValue.assign(rC, vector<int>(cC * 4, UNKNOWN));
        allSpaces.clear();
        for (int i =0; i < 6; ++i)
            counts[i] = 0;
        
        string line;
        for (int r = 0; r < rC; ++r)
        {
            cin >> line;
            for (int c = 0; c < cC; ++c)
            {
                AddHexToGrid(line[c], r, c * 4);
            }
        }
        
        cC *= 4;
        
        for (int r = 0; r < rC; ++r)
        {
            for (int c = 0; c <cC; ++c)
            {
                if (grid[r][c] && positionValue[r][c] == UNKNOWN)
                {
                    int shapePos = ++currentPos;
                    ExpandShape(r, c, shapePos, allSpaces);
                    
                    int count = 0;
                    for (vector<Pos>::const_iterator iter = allSpaces.begin(); iter != allSpaces.end();
                        ++iter)
                    {
                        if (positionValue[iter->r][iter->c] == 0
                            && SpaceIsInner(iter->r, iter->c, ++currentPos, shapePos))
                        {
                            ++count;
                        }
                    }
                    ++counts[count];
                }
            }
        }
        
        cout << "Case " << T++ << ": ";
        
        PrintAll(1);
        PrintAll(5);
        PrintAll(3);
        PrintAll(2);
        PrintAll(4);
        PrintAll(0);
        
        cout << '\n';
    }
}