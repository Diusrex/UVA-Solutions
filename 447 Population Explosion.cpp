#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

const int SIZE = 20;

void IncreaseNeighborCounts(vector<vector<int> >& numNeighbors, const int& x, const int& y)
{
    for (int yc = -1; yc < 2; ++yc)
    {
        int currentY = y + yc;
            
        if (currentY < 0 || currentY >= SIZE)
            continue;
        
        for (int xc = -1; xc < 2; ++xc)
        {
            if (xc == 0 && yc == 0)
                continue;
                
            int currentX = x + xc;
            if (currentX < 0 || currentX >= SIZE)
                continue;
            
            ++numNeighbors[currentY][currentX];
        }
    }
}

void ReadInput(int & numYears, vector<string>& positionIcon, vector<vector<int> >& numNeighbors)
{
    // clear old
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            positionIcon[y][x] = ' ';
            numNeighbors[y][x] = 0;
        }
    }
    
    cin >> numYears;
    cin.ignore();
    
    string line;
    while (getline(cin, line) && line != "")
    {
        stringstream ss(line);
        int x, y;
        ss >> y >> x;
        --x; --y;
        
        positionIcon[y][x] = 'O';
        IncreaseNeighborCounts(numNeighbors, x, y);
    }
}



void RunSimulation(vector<string>& positionIcon, vector<vector<int> >& numNeighbors)
{
    vector<string> tempPositionIcon(SIZE, string(SIZE, ' '));
    vector<vector<int> > tempNumNeighbors(SIZE, vector<int>(SIZE, 0));
    
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            int neighborCount = numNeighbors[y][x];
            if (neighborCount == 3 || (positionIcon[y][x] == 'O' && neighborCount == 2))
            {
                IncreaseNeighborCounts(tempNumNeighbors, x, y);
                tempPositionIcon[y][x] = 'O';
            }
        }
    }
    
    positionIcon.swap(tempPositionIcon);
    numNeighbors.swap(tempNumNeighbors);
}

void PrintOut(const vector<string>& positionIcon)
{
    cout << string(SIZE, '*') << '\n';
    for (int y = 0; y < SIZE; ++y)
    {
        cout << positionIcon[y] << '\n';
    }
}
int main()
{
    vector<string> positionInfo(SIZE, string(SIZE, ' '));
    vector<vector<int> > numNeighbors(SIZE, vector<int>(SIZE));

    int T;
    cin >> T;
    
    bool first = true;
    while (T--)
    {
        if (!first)
            cout << "\n";
        first = false;
        
        int numYears;
        ReadInput(numYears, positionInfo, numNeighbors);
        
        if (numYears > 0)
        {
            --numYears;
            PrintOut(positionInfo);
        }
        
        while (numYears--)
        {
            RunSimulation(positionInfo, numNeighbors);
            PrintOut(positionInfo);
        }
        cout << string(SIZE, '*') << '\n';
    }
    
}