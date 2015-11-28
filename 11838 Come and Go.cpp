#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> canTravelTo[2005];
int dfs_num[2005];
int dfs_low[2005];
bool visited[2005];
int dfsNumberCounter;

// Need everything to be in one SCC
bool IsInOneSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    
    visited[u] = true;
    
    for (int adj : canTravelTo[u])
    {
        if (dfs_num[adj] == -1)
            if (!IsInOneSCC(adj))
                return false;
            
        if (visited[adj])
            dfs_low[u] = min(dfs_low[u], dfs_low[adj]);
    }
    
    if (dfs_low[u] == dfs_num[u] && u != 0)
        return false;
    
    return true;
}

bool AllVisited(int N)
{
    for (int i = 0; i < N; ++i)
        if (!visited[i])
            return false;
        
    return true;
}

int main()
{
    int N, M;
    
    while (cin >> N >> M, N)
    {
        for (int i = 0; i < N; ++i)
        {
            canTravelTo[i].clear();
            dfs_num[i] = -1;
            visited[i] = false;
        }
        
        while (M--)
        {
            int V, W, P;
            cin >> V >> W >> P;
            --V; --W;
            canTravelTo[V].push_back(W);
            if (P == 2)
                canTravelTo[W].push_back(V);
        }
        
        dfsNumberCounter = 0;
        if (IsInOneSCC(0) && AllVisited(N))
            cout << "1\n";
        else
            cout << "0\n";
    }
}