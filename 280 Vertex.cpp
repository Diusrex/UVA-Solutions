#include <iostream>

using namespace std;

bool reachable[105][105];

int main()
{
    int N;
    while (cin >> N, N)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
                reachable[i][j] = false;
        }
        
        int start;
        
        while (cin >> start, start)
        {
            int next;
            while (cin >> next, next)
                reachable[start][next] = true;
        }
        
        
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    reachable[i][j] |= reachable[i][k] && reachable[k][j];
                
                
        int numQueries;
        cin >> numQueries;
        while (numQueries--)
        {
            int q;
            cin >> q;
            
            int count = 0;
            for (int i = 1; i <= N; ++i)
                if (!reachable[q][i])
                    ++count;
            
            cout << count;
            for (int i = 1; i <= N; ++i)
                if (!reachable[q][i])
                    cout << ' ' << i;
                
            cout << '\n';
        }
    }
}