#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int Inf = 1e9;
const int MaxNumStars = 1005;

struct Edge
{
    int to, c;
};

vector<Edge> edges[MaxNumStars];
int distances[MaxNumStars];

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        
        for (int i = 0; i < N; ++i)
        {
            edges[i].clear();
            distances[i] = Inf;
        }
        
        Edge e;
        while (E--)
        {
            int x;
            cin >> x >> e.to >> e.c;
            edges[x].push_back(e);
        }
        
        for (int t = 0; t < N - 1; ++t)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int e = 0; e < edges[j].size(); ++e)
                {
                    distances[edges[j][e].to] = min(distances[edges[j][e].to], distances[j] + edges[j][e].c);
                }
            }
        }
        
        bool canGoLower = false;
        
        for (int j = 0; j < N; ++j)
        {
            for (int e = 0; e < edges[j].size(); ++e)
            {
                canGoLower |= distances[edges[j][e].to] > distances[j] + edges[j][e].c;
            }
        }
        cout << (canGoLower ? "possible\n" : "not possible\n");
    }
}