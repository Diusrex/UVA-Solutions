#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Expand(const char attack, const char defend, char & newGrid)
{
    if (attack == 'R' && defend == 'S')
        newGrid = 'R';
    
    else if (attack == 'S' && defend == 'P')
        newGrid = 'S';
    
    else if (attack == 'P' && defend == 'R')
        newGrid = 'P';
}

void RunGame(vector<string> & grid, const int xSize, const int ySize, int turns)
{
    string blankLine = "";
    for (int x = 0; x < xSize; ++x)
        blankLine += ".";
        
    while (turns--)
    {
        vector<string> newGrid(ySize, blankLine);
        
        for (int x = 0; x < xSize; ++x)
        {
            for (int y = 0; y < ySize; ++y)
            {
                if (newGrid[y][x] == '.')
                    newGrid[y][x] = grid[y][x];
                    
                for (int xc = -1; xc < 2; ++xc)
                {
                    if (x + xc >= 0 && x + xc < xSize)
                    {
                        for (int yc = -1; yc < 2; ++yc)
                        {
                            if (y + yc >= 0 && y + yc < ySize
                                && xc != yc && xc != -yc)
                                Expand(grid[y][x], grid[y + yc][x + xc], newGrid[y + yc][x + xc]);
                        }
                    }
                }
            }
        }
        
        grid = newGrid;
    }
}

int main()
{
    int T;
    cin >> T;
    
    string separator = "";
    
    while (T--)
    {
        int xSize, ySize, turns;
        cin >> ySize >> xSize >> turns;
        
        vector<string> grid(ySize);
        
        for (int y = 0; y < ySize; ++y)
        {
            cin >> grid[y];
        }
        
        RunGame(grid, xSize, ySize, turns);
        
        cout << separator;
        separator = "\n";
        
        for (int y = 0; y < ySize; ++y)
        {
            cout << grid[y] << '\n';
        }
    }

}