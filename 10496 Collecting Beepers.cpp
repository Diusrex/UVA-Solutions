#include <iostream>
#include <cmath>

using namespace std;

const int Inf = 1e9;
int xPos[13], yPos[13];
int distances[13][13];

int N, wanted;

int bestCost[13][1 << 12];

inline bool IsReached(int index, int reached)
{
    return (1 << index) & reached;
}

int GetBestCost(int pos, int reached)
{
    reached |= 1 << pos;
    
    if (reached == wanted)
        return distances[pos][0];
    
    int &cost = bestCost[pos][reached];
    
    if (cost == -1)
    {
        cost = Inf;
        for (int i = 1; i < N; ++i)
        {
            if (!IsReached(i, reached))
                cost = min(cost, GetBestCost(i, reached) + distances[pos][i]);
        }
    }
    
    return cost;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        // Don't care about these...
        int R, C;
        cin >> R >> C;
        
        cin >> xPos[0] >> yPos[0];
        
        cin >> N;
        ++N;
        
        for (int i = 1; i < N; ++i)
        {
            cin >> xPos[i] >> yPos[i];
            for (int j = 0; j < i; ++j)
                distances[i][j] = distances[j][i] =
                    abs(xPos[i] - xPos[j]) + abs(yPos[i] - yPos[j]);
        }
        
        wanted = (1 << N) - 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < wanted; ++j)
                bestCost[i][j] = -1;
        
        cout << "The shortest path has length " << GetBestCost(0, 0) << '\n';
    }
}