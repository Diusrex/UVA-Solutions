#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > nodesConnectedTo;

void TryOut(int node, vector<bool> &notHit, const int &ignoring)
{
    notHit[node] = false;
    for (vector<int>::const_iterator iter = nodesConnectedTo[node].begin();
        iter != nodesConnectedTo[node].end(); ++iter)
    {
        if (*iter != ignoring && notHit[*iter])
            TryOut(*iter, notHit, ignoring);
    }
}

void PrintBlank(int N)
{
    N = N * 2 - 1;
    cout << '+';
    for (int i = 0; i < N; ++i)
        cout << '-';
    cout << "+\n";
}

int main()
{
    int T;
    cin >> T;
    
    vector<vector<bool> > dominating;
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        
        dominating.assign(N, vector<bool>(N, true));
        nodesConnectedTo.assign(N, vector<int>());
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                int possible;
                cin >> possible;
                if (possible)
                    nodesConnectedTo[i].push_back(j);
            }
        }
        
        vector<bool> disconnected(N, true);
        TryOut(0, disconnected, -1);
        
        for (int ignore = 1; ignore < N; ++ignore)
            TryOut(0, dominating[ignore], ignore);
            
        cout << "Case " << t << ":\n";
        PrintBlank(N);
        for (int i = 0; i < N; ++i)
        {
            cout << '|';
            for (int j = 0; j < N; ++j)
            {
                if (dominating[i][j] && !disconnected[j])
                    cout << "Y|";
                else
                    cout << "N|";
            }
            cout << '\n';
            PrintBlank(N);
        }
    }
}