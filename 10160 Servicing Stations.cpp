#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef bitset<35> bset;

// Is quite fast (top 3) with the least obvious speedup being only search in connected components
// (which shaved the last 0.02 seconds off)
// Also ensures that, if trying to skip node, that it can be completed
// Nothing really fancy other than those two
// A further improvement could be, for nodes that are only connected to a single other node who is not connected to a service station, know will just include the other guy
    // This could be advanced quite far along the graph

int N;
bset allIncluded;

// Who is connected to
bset connections[35];
// Who may be connected after this node. Based on following checks
bset connectedAfter[35];

// To find connected components
void dfs(int node, bset &included)
{
    included[node] = true;
    for (int i = 0; i < N; ++i)
        if (connections[node][i] && !included[i])
            dfs(i, included);
}


void FindLowestCost(bset connected, int currentNode, int currentCount, int & bestCount)
{
    // All are connected
    if (connected == allIncluded)
    {
        bestCount = min(bestCount, currentCount);
        return;
    }
    
    // No point in continuing
    // If is equal to bestCount - 1, will need to add at least one more node
    if (currentCount >= bestCount - 1)
        return;
    
    // Cannot continue. Don't think this should be reached
    if (currentNode == N)
    {
        return;
    }
    
    // Try including this guy, but only if he will add any usefulness
    bset whenAdded = connected | connections[currentNode];
    if (connected != whenAdded)
    {
        FindLowestCost(whenAdded, currentNode + 1, currentCount + 1, bestCount);
    }
    
    // Try not including this guy. But only if there is still a valid solution after
    if ((connected | connectedAfter[currentNode]) == allIncluded)
    {
        FindLowestCost(connected, currentNode + 1, currentCount, bestCount);
    }
}

int main()
{
    int M;
    
    while (cin >> N >> M, N)
    {
        for (int i = 0; i < N; ++i)
        {
            connections[i].reset();
            connections[i].set(i);
        }
        
        allIncluded.reset();
        for (int i = 0; i < N; ++i)
            allIncluded.set(i);
        
        while (M--)
        {
            int i, j;
            cin >> i >> j;
            --i; --j;
            
            connections[i].set(j);
            connections[j].set(i);
        }
        // Since nothing can be reached after it
        connectedAfter[N - 1].reset();
        for (int i = N - 2; i >= 0; --i)
            connectedAfter[i] = connectedAfter[i + 1] | connections[i + 1];
        
        // Will match for the overallIncluded
        bset overallIncluded;
        int bestOverall = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if (!overallIncluded[i])
            {
                // Will need to include i, or part of its component
                bset component;
                dfs(i, component);
                
                bset outsideComponent = allIncluded ^ component;
                int componentBest = N;
                FindLowestCost(outsideComponent, 0, 0, componentBest);
                
                overallIncluded |= component;
                bestOverall += componentBest;
            }
        }
        cout << bestOverall << '\n';
    }
}