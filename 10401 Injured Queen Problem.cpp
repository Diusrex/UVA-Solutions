#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int GridSize = 16;

int N;
string status;

long long numPossible[GridSize][GridSize];
int visited[GridSize][GridSize];

long long GetNumPossible(int col, int previousRow, const int visit);
long long Calculate(int col, int previousRow, const int visit)
{
    if (status[col] != '?')
    {
        int currentRow = (status[col] - '1');
        if (currentRow > 10 || currentRow < 0)
            currentRow = (status[col] - 'A' + 9); // A is 9
        // Only allow if the difference is more than 1
        if (abs(previousRow - currentRow) <= 1)
            return 0;
        return GetNumPossible(col + 1, currentRow, visit);
    }
    else
    {
        long long total = 0;
        for (int i = 0; i < N; ++i)
        {
            if (abs(i - previousRow) <= 1)
                continue;
            
            total += GetNumPossible(col + 1, i, visit);
        }
        
        return total;
    }
}

long long GetNumPossible(int col, int previousRow, const int visit)
{
    if (col == N)
        return 1;
    
    if (visited[col][previousRow] != visit)
    {
        numPossible[col][previousRow] = Calculate(col, previousRow, visit);
        visited[col][previousRow] = visit;
    }
    
    return numPossible[col][previousRow];
}

int main()
{
    int T = 1;
    while (cin >> status)
    {
        if (status.empty())
            continue;
        N = status.size();
        
        cout << GetNumPossible(0, -3, T) << '\n';
        ++T;
    }
}
