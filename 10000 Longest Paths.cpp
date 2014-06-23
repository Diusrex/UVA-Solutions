#include <cstdio>
#include <vector>

using namespace std;

int GetLongestPath(int node, const vector<vector<bool> >& canTravelTo, vector<int> & longestPath, const int& n, const int start)
{
    if (longestPath[node] == -1)
    {
        int longestRoute = 0;
        int bestNode = -1;
        
        for (int i = 0; i < n; ++i)
        {
            if (canTravelTo[i][node])
            {
                int routeLength = GetLongestPath(i, canTravelTo, longestPath, n, start) + 1;
                
                
                if ((routeLength > 1 || i == start) && routeLength > longestRoute)
                {
                    longestRoute = routeLength;
                    bestNode = i;
                }
            }
        }
        
        if (bestNode != -1)
        {
            longestPath[node] = longestRoute;
        }
        else
            longestPath[node] = 0;
    }
    
    return longestPath[node];
}

int main()
{
    int t = 1, n, start;
    
    while (scanf("%d %d", &n, &start), n)
    {
        --start;
        
        vector<vector<bool> > canTravelTo(n, vector<bool> (n, false));
        
        int p, q;
        
        while (scanf("%d %d", &p, &q), q)
        {
            canTravelTo[p - 1][q - 1] = true;
        }
        
        vector<int> longestPath(n, -1);
        longestPath[start] = 0;
        
        int bestPathLen = 0;
        int bestNode = start;
        
        for (int i = 0; i < n; ++i)
        {
            if (i != start)
            {
                int currentPathLen = GetLongestPath(i, canTravelTo, longestPath, n, start);
                
                if (currentPathLen > bestPathLen)
                {
                    bestPathLen = currentPathLen;
                    bestNode = i;
                }
            }
        }
            
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t, start + 1, bestPathLen, bestNode + 1);
        
        ++t;
    }
}