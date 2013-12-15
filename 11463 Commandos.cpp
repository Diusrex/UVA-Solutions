#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

void DoDfs(vector<int>& dist, const vector<vector<bool> >& connected, int startPoint, int N)
{
    queue<pair<int, int> > q;
        
    q.push(make_pair(startPoint, 0));
        
    dist[startPoint] = 0;
        
    while (!q.empty())
    {
        pair<int, int> info = q.front();
        q.pop();
            
        for (int i = 0; i < N; ++i)
        {
            if (connected[info.first][i] && dist[i] == -1)
            {
                q.push(make_pair(i, info.second + 1));
                dist[i] = info.second + 1;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int N, R;
        cin >> N >> R;
        
        vector<vector<bool> > connected(N, vector<bool>(N, false));
        
        for (int i = 0; i < R; ++i)
        {
            int first, second;
            cin >> first >> second;
            connected[first][second] = true;
            connected[second][first] = true;
        }
        
        vector<int> distFromStart(N, -1);
        vector<int> distFromEnd(N, -1);
        
        int start, end;
        cin >> start >> end;
        DoDfs(distFromStart, connected, start, N);
        DoDfs(distFromEnd, connected, end, N);
        
        int farthest = 0;
        
        for (int i = 0; i < N; ++i)
            farthest = max(distFromStart[i] + distFromEnd[i], farthest);
        
        cout << "Case " << t << ": " << farthest << '\n';
    }

}