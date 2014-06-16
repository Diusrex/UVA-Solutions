#include <string>
#include <cstdio>
#include <set>

using namespace std;


int N;

// string will be [x * ySize + y]
// so at [pos], y = pos % ySize, x = pos / ySize
inline int convertSpot(const int& x, const int &y) { return x * N + y; }


int main()
{
    
    
    while (scanf("%d", &N), N)
    {
        int player = 0;
        set<string> enteredItems;
        
        string grid(N * N, '0');
        string grid90(grid);
        string grid180(grid);
        string grid270(grid);
        
        int winner = -1, winTurn;
        
        // Run through each play
        for (int t = 0; t < N * 2; ++t)
        {
            int x, y;
            char move;
            
            scanf("%d %d %c", &x, &y, &move);
            
            
            if (winner != -1)
                continue;
            
            --x; --y;
            
            int pos = convertSpot(x, y);
            
            if (move == '+')
                grid[pos] = '1';
            else
                grid[pos] = '0';
            
            if (enteredItems.find(grid) != enteredItems.end())
            {
                winner = 1 - player;
                winTurn = t;
            }
            
            else
            {
                grid90[convertSpot(y, N - 1 - x)] = grid180[N * N - 1 - pos] = grid270[convertSpot(N -1 - y, x)] = grid[pos];
                
                enteredItems.insert(grid);
                enteredItems.insert(grid90);
                enteredItems.insert(grid180);
                enteredItems.insert(grid270);
            }
            
            player = 1 - player;
        }
        
        if (winner == -1)
            printf("Draw\n");
        else
            printf("Player %d wins on move %d\n", winner + 1, winTurn + 1);
    }
}