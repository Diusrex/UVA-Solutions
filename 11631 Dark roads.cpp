#include <iostream>
#include <algorithm>

using namespace std;

struct Edge
{
    int i, j;
    int cost;

    bool operator<(const Edge& other) const
    {
        return cost < other.cost;
    }
};

const int MaxNode = 200005;
const int MaxEdge = 200005;

bool isConnected[MaxNode];
Edge edges[MaxEdge];

int main()
{
    int N, E;

    while (cin >> N >> E, N)
    {
        int overallCost = 0;
        for (int i = 0; i < E; ++i)
        {
            cin >> edges[i].i >> edges[i].j >> edges[i].cost;
            overallCost += edges[i].cost;
        }

        sort(edges, edges + E);
        for (int i = 0; i < N; ++i)
            isConnected[i] = false;

        isConnected[edges[0].i] = isConnected[edges[0].j] = true;
        int minCost = edges[0].cost;
        int lowestUnusedEdge = 1;
        // Already connected 2
        N -= 2;
        while (N--)
        {
            int usedEdge = lowestUnusedEdge;
            // WHile are both included, or neither is included
            for (; isConnected[edges[usedEdge].i] == isConnected[edges[usedEdge].j]; ++usedEdge)
                ;

            if (usedEdge == lowestUnusedEdge)
                ++lowestUnusedEdge;

            isConnected[edges[usedEdge].i] = isConnected[edges[usedEdge].j] = true;
            minCost += edges[usedEdge].cost;
        }

        cout << overallCost - minCost << '\n';
    }
}
