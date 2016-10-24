#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MaxN = 65;

int N;
vector<int> adj[MaxN * 2];
vector<int> adjrev[MaxN * 2];
// If it is true in the solution
bool included[MaxN];
int dfstime[MaxN * 2], dfsorder[MaxN * 2];
int group[MaxN * 2];

inline int Other(int v)
{
    return v < N ? v + N : v - N;
}

inline int Var(int v)
{
    return v % N;
}

// 1 if is var, 0 if is opposite
inline int Type(int v)
{
    return 1 - v / N;
}

void SatClear()
{
    for (int i = 0; i < MaxN * 2; ++i)
    {
        adj[i].clear();
        adjrev[i].clear();
    }
}

void dfs(int v, int& dfst)
{
    if (dfstime[v] != -1)
        return;
    dfstime[v] = -2;
    for (int i = 0; i < adjrev[v].size(); ++i)
        dfs(adjrev[v][i], dfst);
    
    dfstime[v] = dfst++;
}

void dfsGroup(int v, int currentGroup)
{
    if (group[v] != -1)
        return;
    group[v] = currentGroup;
    for (int i = 0; i < adj[v].size(); ++i)
        dfsGroup(adj[v][i], currentGroup);
}

// a or b
// Call with Other(a) b to get ~a v b
void AddEdge(int a, int b)
{
    adj[Other(a)].push_back(b);
    adjrev[a].push_back(Other(b));
    adj[Other(b)].push_back(a);
    adjrev[b].push_back(Other(a));
}

bool Solve()
{
    memset(dfstime, -1, sizeof dfstime);
    const int NN = N + N;
    int dfst = 0;
    for (int i = 0; i < NN; ++i)
        dfs(i, dfst);
    
    for (int i = 0; i < NN; ++i)
        dfsorder[NN - dfstime[i] - 1] = i;
    
    memset(group, -1, sizeof group);
    for (int i = 0; i < NN; ++i)
    {
        dfsGroup(dfsorder[i], i);
    }
    
    for (int i = 0; i < N; ++i)
    {
        // i and ~i are in same group
        if (group[i] == group[i + N])
            return false;
        included[i] = group[i] <= group[i + N];
    }
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int S, A, M;
        cin >> S >> A >> M;
        
        N = S + A;
        const int AveOffset = S;
        
        SatClear();
        
        while (M--)
        {
            int s1, a1, s2, a2;
            cin >> s1 >> a1 >> s2 >> a2;
            --s1; --a1; --s2; --a2;
            a1 += AveOffset;
            a2 += AveOffset;
            
            if (a1 == a2)
            {
                // Travels along a1
                if (s1 < s2)
                    AddEdge(a1, a1);
                else
                    AddEdge(Other(a1), Other(a1));
            }
            else if (s1 == s2)
            {
                // Travels along s1
                if (a1 < a2)
                    AddEdge(s1, s1);
                else
                    AddEdge(Other(s1), Other(s1));
            }
            else
            {
                if (a1 > a2)
                {
                    s1 = Other(s1);
                    s2 = Other(s2);
                }
                if (s1 > s2)
                {
                    a1 = Other(a1);
                    a2 = Other(a2);
                }
                
                AddEdge(s1, a1);
                AddEdge(s1, s2);
                AddEdge(a2, a1);
                AddEdge(a2, s2);
            }
        }
        
        if (Solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}