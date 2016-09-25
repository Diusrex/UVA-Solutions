#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int N;
int encounteredNum[505];

int squaredDist[505][505];
int xPos[505], yPos[505];

void DFS(int node, const int maxDist, const int attempt)
{
    encounteredNum[node] = attempt;
    
    for (int i = 0; i < N; ++i)
    {
        if (encounteredNum[i] != attempt && squaredDist[node][i] <= maxDist)
            DFS(i, maxDist, attempt);
    }
}

bool CanConnect(int outposts, const int maxDistance, const int attempt)
{
    for (int i = 0; i < N && outposts >= 0; ++i)
    {
        if (encounteredNum[i] != attempt)
        {
            DFS(i, maxDistance, attempt);
            --outposts;
        }
    }
    
    return outposts >= 0;
}

inline int SquaredDist(int i, int j)
{
    const int xDiff = xPos[i] - xPos[j], yDiff = yPos[i] - yPos[j];
    return xDiff * xDiff + yDiff * yDiff;
}

int main()
{
    int T;
    cin >> T;
    cout << fixed << setprecision(2);
    while (T--)
    {
        int S;
        cin >> S >> N;
        
        vector<int> distances;
        int numAttempts = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> xPos[i] >> yPos[i];
            encounteredNum[i] = numAttempts;
            
            for (int j = 0; j < i; ++j)
            {
                squaredDist[i][j] = squaredDist[j][i] = SquaredDist(i, j);
                distances.push_back(squaredDist[i][j]);
            }
        }
        
        sort(distances.begin(), distances.end());
        
        // Do binary search now
        int start = 0, end = distances.size();
        
        while (start != end)
        {
            int mid = (start + end) / 2;
            
            const int allowedSquaredDist = distances[mid];
            
            if (CanConnect(S, allowedSquaredDist, numAttempts))
                end = mid; // Can possibly use less distance
            else
                start = mid + 1; // Will need more distance
            ++numAttempts;
        }
        
        cout << sqrt(distances[start]) << '\n';
    }
}