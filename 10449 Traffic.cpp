#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const long long Inf = LLONG_MAX;

struct Edge
{
    int from, to, cost;
};

// Possible for n = 0!!
vector<int> busyness;
vector<long long> distances;
vector<Edge> allEdges;
vector<Edge> allEdgesByNode[205];
int predecessor[205];
bool inNegativeCycle[205];

const int White = 0, Gray = 1, Black = 2;
int color[205];

void PushAlongNegativeCycle(int node, long long newCost)
{
    if (inNegativeCycle[node])
        return;
    
    inNegativeCycle[node] = true;
    
    for (int e = 0; e < allEdgesByNode[node].size(); ++e)
    {
        int toNode = allEdgesByNode[node][e].to;
        if (newCost + allEdgesByNode[node][e].cost < distances[toNode])
            PushAlongNegativeCycle(toNode, newCost + allEdgesByNode[node][e].cost);
    }
}

int ExpandPredecessor(int node)
{
    if (color[node] != White)
        return color[node];
    color[node] = Gray;
    
    // Not part of a cycle at all
    if (predecessor[node] == -1)
        return color[node] = Black;
    
    int newColor = ExpandPredecessor(predecessor[node]);
    inNegativeCycle[node] = (newColor == Gray);
    
    return color[node] = newColor;
}

void ExpandNegativeCycle(int node)
{
    inNegativeCycle[node] = true;
    for (int e = 0; e < allEdgesByNode[node].size(); ++e)
    {
        int travelTo = allEdgesByNode[node][e].to;
        if (!inNegativeCycle[travelTo])
            ExpandNegativeCycle(travelTo);
    }
}

void BellmanFord(int V, int E, int source)
{
    distances.resize(V);
    
    for (int i = 0; i < V; ++i)
        distances[i] = (i == source) ? 0 : Inf;
    
    for (int i = 0; i < V; ++i)
        predecessor[i] = -1;
    
    // Relax edges
    for (int i = 0; i < V - 1; ++i)
    {
        for (int e = 0; e < E; ++e)
        {
            const Edge &edge = allEdges[e];
            if (distances[edge.from] != Inf && distances[edge.from] + edge.cost < distances[edge.to])
            {
                distances[edge.to] = distances[edge.from] + edge.cost;
                predecessor[edge.to] = edge.from;
            }
        }
    }
    
    // Go along the predecessor graph
    for (int i = 0; i < V; ++i)
        color[i] = White;
    
    // Find all nodes that are part of a negative cycle
    for (int i = 0; i < V; ++i)
        ExpandPredecessor(i);
    
    // Now, expand from all nodes that are in a negative cycle - they cause all children to become negative cycle nodes
    for (int i = 0; i < V; ++i)
        if (inNegativeCycle[i])
            ExpandNegativeCycle(i);
}

int main()
{
    int V;
    int T = 1;
    
    while (cin >> V)
    {
        busyness.resize(V);
        
        for (int i = 0; i < V; ++i)
        {
            cin >> busyness[i];
            inNegativeCycle[i] = false;
            allEdgesByNode[i].clear();
        }
        
        int E;
        cin >> E;
        
        allEdges.resize(E);
        
        for (int i = 0; i < E; ++i)
        {
            cin >> allEdges[i].from >> allEdges[i].to;
            --allEdges[i].from;
            --allEdges[i].to;
            
            
            int diff = busyness[allEdges[i].to] - busyness[allEdges[i].from];
            allEdges[i].cost = diff * diff * diff;
            
            allEdgesByNode[allEdges[i].from].push_back(allEdges[i]);
        }
        BellmanFord(V, E, 0);
        
        int Q;
        cin >> Q;
        
        cout << "Set #" << T++ << '\n';
        for (int i = 0; i < Q; ++i)
        {
            int to;
            cin >> to;
            --to;
            
            if (distances[to] < 3 || inNegativeCycle[to] || distances[to] == Inf)
                cout << "?\n";
            else
                cout << distances[to] << '\n';
            
        }
    }
}