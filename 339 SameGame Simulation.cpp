#include <cstdio>
#include <vector>

using namespace std;

void Flood(const vector<vector<int> >& grid, vector<vector<bool> >& marked, int x, int y, int& numMarked)
{
    marked[x][y] = true;
    ++numMarked;
    
    if (x + 1 < grid.size() && !marked[x + 1][y] && grid[x + 1][y] == grid[x][y])
        Flood(grid, marked, x + 1, y, numMarked);
    
    if (y + 1 < grid[x].size() && !marked[x][y + 1] && grid[x][y + 1] == grid[x][y])
        Flood(grid, marked, x, y + 1, numMarked);
        
    if (x - 1 >= 0 && !marked[x - 1][y] && grid[x - 1][y] == grid[x][y])
        Flood(grid, marked, x - 1, y, numMarked);
    
    if (y - 1 >= 0 && !marked[x][y - 1] && grid[x][y - 1] == grid[x][y])
        Flood(grid, marked, x, y - 1, numMarked);
}

void PrintGrid(const vector<vector<int> >& grid, int xSize, int ySize)
{
    for (int y = ySize - 1; y >= 0; --y)
    {
        printf("\n   ");
        for (int x = 0; x < xSize; ++x)
        {
            if (grid.size() > x && grid[x].size() > y)
                printf(" %d", grid[x][y]);
            else
                printf("  ");
        }
        printf(" ");
    }
    
    printf("\n");
}


int main()
{
    int numRow, numCol;
    
    int t(1);
    while (scanf("%d %d", &numRow, &numCol), numRow && numCol)
    {
        // [x][y]
        vector<vector<int> > grid(numCol, vector<int>(numRow));
        
        for (int y = 0; y < numRow; ++y)
        {
            for (int x = 0; x < numCol; ++x)
            {
                scanf("%d", &grid[x][y]);
            }
        }
        
        int x, y;
        
        while (scanf("%d %d", &y, &x), y, x)
        {
            --y; --x;
            
            if (x < grid.size() && y < grid[x].size())
            {
                vector<vector<bool> > marked(numCol, vector<bool>(numRow, false));
                
                int numMarked(0);
                
                
                Flood(grid, marked, x, y, numMarked);
                
                if (numMarked <= 1)
                    continue;
                
                for (int x = grid.size() - 1; x >= 0; --x)
                {
                    for (int y = grid[x].size() - 1; y >= 0; --y)
                    {
                        if (marked[x][y])
                        {
                            grid[x].erase(grid[x].begin() + y);
                        }
                    }
                    
                    if (grid[x].size() == 0)
                        grid.erase(grid.begin() + x);
                }
            }
            
        }
        
        if (t != 1)
            printf("\n");
        printf("Grid %d.", t++);
        
        if (grid.size() == 0)
        {
            printf("\n    Game Won\n");
        }
        
        else
        {
            PrintGrid(grid, numCol, numRow);
        }
    }

}