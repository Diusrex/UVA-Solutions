#include <iostream>

using namespace std;


int R, C;

bool passable[105][105];
bool hasSticker[105][105];

const int NumChanges = 4;

// Right is - 1, left is +1
int rChange[NumChanges] = {-1, 0, 1, 0};
int cChange[NumChanges] = {0, -1, 0, 1};

int inputToDirection[128];

inline bool IsValid(int newR, int newC)
{
    return newR >= 0 && newR < R && newC >= 0 && newC < C && passable[newR][newC];
}


int main()
{
    inputToDirection['N'] = 0;
    inputToDirection['S'] = 2;
    inputToDirection['L'] = 3;
    inputToDirection['O'] = 1;
    
    int S;
    string line;
    while (cin >> R >> C >> S, R)
    {
        int robotR, robotC, orientation;
        for (int r = 0; r < R; ++r)
        {
            cin >> line;
            
            for (int c = 0; c < C; ++c)
            {
                if (line[c] == '#')
                    passable[r][c] = false;
                else
                {
                    passable[r][c] = true;
                    if (line[c] == '*')
                        hasSticker[r][c] = true;
                    else
                    {
                        hasSticker[r][c] = false;
                        if (line[c] != '.')
                        {
                            robotR = r; robotC = c;
                            orientation = inputToDirection[line[c]];
                        }
                    }
                }
            }
        }
        
        cin >> line;
        int numStickers = 0;
        for (int i = 0; i < S; ++i)
        {
            if (line[i] == 'D')
                orientation = (orientation - 1 + NumChanges) % NumChanges;
            else if (line[i] == 'E')
                orientation = (orientation + 1) % NumChanges;
            else
            {
                int newR = robotR + rChange[orientation], newC = robotC + cChange[orientation];
                if (IsValid(newR, newC))
                {
                    robotR = newR; robotC = newC;
                    if (hasSticker[robotR][robotC])
                    {
                        ++numStickers;
                        hasSticker[robotR][robotC] = false;
                    }
                }
            }
        }
        cout << numStickers << '\n';
    }
}