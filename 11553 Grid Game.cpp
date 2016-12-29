#include <iostream>

using namespace std;

// [rows][columns]
int BestScore[1 << 8 + 1][1 << 8 + 1];
bool Visited[1 << 8 + 1][1 << 8 + 1];

// [r][c]
int grid[8][8];
int N;

inline bool Used(int num, int line)
{
    return line & (1 << num);
}

int GetBestScore(int rows, int columns)
{
    // All have been taken
    if (rows == ((1 << N) - 1))
        return 0;
    
    if (!Visited[rows][columns])
    {
        BestScore[rows][columns] = -1e8;
        
        for (int row = 0; row < N; ++row)
        {
            if (Used(row, rows))
                continue;
            
            int bestForRow = 1e8;
            for (int column = 0; column < N; ++column)
            {
                if (Used(column, columns))
                    continue;
                
                bestForRow = min(bestForRow, grid[row][column] + GetBestScore(rows | (1 << row), columns | (1 << column)));
            }
            
            BestScore[rows][columns] = max(BestScore[rows][columns], bestForRow);
        }
        
        Visited[rows][columns] = true;
    }
    
    return BestScore[rows][columns];
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                cin >> grid[r][c];
            
        for (int r = 0; r < (1 << N) - 1; ++r)
            for (int c = 0; c < (1 << N) - 1; ++c)
                Visited[r][c] = false;
            
        cout << GetBestScore(0, 0) << '\n';
    }
}