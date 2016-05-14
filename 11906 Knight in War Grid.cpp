#include <iostream>

using namespace std;

int R, C, M, N;
bool passable[105][105];

bool Valid(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C && passable[r][c];
}

int numOdd, numEven;
bool visited[105][105];

const int NumDirs = 4;
int rShifts[NumDirs] = {1, 1, -1, -1};
int cShifts[NumDirs] = {1, -1, 1, -1};

const int ZeroShifts = 4;
int rZeroShifts[ZeroShifts] = {1, -1, 0, 0};
int cZeroShifts[ZeroShifts] = {0, 0, 1, -1};

void dfs(int r, int c);

int TryShifts(int r, int c, int rMultiple, int cMultiple)
{
    int count = 0;
    for (int i = 0; i < NumDirs; ++i)
    {
        const int newR = r + rMultiple * rShifts[i], newC = c + cMultiple * cShifts[i];
        if (Valid(newR, newC))
        {
            ++count;
            if (!visited[newR][newC])
                dfs(newR, newC);
        }
    }
    return count;
}

void dfs(int r, int c)
{
    visited[r][c] = true;
    
    int count;
    if (M == N)
    {
        count = TryShifts(r, c, M, M);
    }
    else if (M == 0 || N == 0)
    {
        count = 0;
        int nonZero = max(M, N);
        for (int i = 0; i < ZeroShifts; ++i)
        {
            const int newR = r + nonZero * rZeroShifts[i], newC = c + nonZero * cZeroShifts[i];
            if (Valid(newR, newC))
            {
                ++count;
                if (!visited[newR][newC])
                    dfs(newR, newC);
            }
        }
    }
    else
    {
        count = TryShifts(r, c, M, N) + TryShifts(r, c, N, M);
    }
    
    if (count & 1)
        ++numOdd;
    else
        ++numEven;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int W;
        cin >> R >> C >> M >> N >> W;
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                passable[r][c] = true;
                visited[r][c] = false;
            }
        }
        
        while (W--)
        {
            int r, c;
            cin >> r >> c;
            
            passable[r][c] = false;
        }
        
        numEven = 0;
        numOdd = 0;
        
        dfs(0, 0);
        
        cout << "Case " << t << ": " << numEven << ' ' << numOdd << '\n';
    }
}