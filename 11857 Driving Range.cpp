#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

// <To, cost>
vector<pii > edges[1000005];

bool taken[1000005];
// <-cost, to>>
priority_queue<pii > pq;

void Process(int node)
{
    taken[node] = true;
    for (int i = 0; i < edges[node].size(); ++i)
    {
        if (!taken[edges[node][i].first])
            pq.push(pii(-edges[node][i].second, edges[node][i].first));
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m, n)
    {
        // reset state
        for (int i = 0; i < n; ++i)
        {
            edges[i].clear();
            taken[i] = false;
        }
        
        while (m--)
        {
            int i, j, cost;
            cin >> i >> j >> cost;
            edges[i].push_back(pii(j, cost));
            edges[j].push_back(pii(i, cost));
        }
        
        Process(0);
        int worstCost = 0;
        
        while (!pq.empty())
        {
            pii current = pq.top();
            pq.pop();
            
            // Node it travels to hasn't been taken yet
            if (!taken[current.second])
            {
                Process(current.second);
                worstCost = max(worstCost, -current.first);
            }
        }
        
        
        bool allConnected = true;
        for (int i = 0; i < n; ++i)
            allConnected &= taken[i];
        
        if (allConnected)
            cout << worstCost << '\n';
        else
            cout << "IMPOSSIBLE\n";
    }
}