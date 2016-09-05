#include <iostream>

using namespace std;

const int GridSize = 105;

int R, C;
// [R][C]
int current[GridSize][GridSize];
int nextGrid[GridSize][GridSize];

const int NumChange = 4;
int rChange[] = {0, 0, -1, 1};
int cChange[] = {-1, 1, 0, 0};

bool IsOfType(int r, int c, int change, int num)
{
    int newR = r + rChange[change], newC = c + cChange[change];
    return newR >= 0 && newR < R && newC >= 0 && newC < C &&
        current[newR][newC] == num;
}

int main()
{
    int N, K;
    
    while (cin >> N >> R >> C >> K, N)
    {
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                cin >> current[r][c];
            }
        }
        
        while (K--)
        {
            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    int attackedBy = (current[r][c] + N - 1) % N;
                    if (IsOfType(r, c, 0, attackedBy) || IsOfType(r, c, 1, attackedBy) ||
                        IsOfType(r, c, 2, attackedBy) || IsOfType(r, c, 3, attackedBy))
                        nextGrid[r][c] = attackedBy;
                    else
                        nextGrid[r][c] = current[r][c];
                }
            }
            
            swap(nextGrid, current);
        }
        for (int r = 0; r < R; ++r)
        {
            cout << current[r][0];
            for (int c = 1; c < C; ++c)
                cout << ' ' << current[r][c];
            cout << '\n';
        }
    }
}