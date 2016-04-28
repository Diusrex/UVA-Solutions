#include <iostream>
#include <vector>
#include <cstring>

// Uses c++ 11

using namespace std;

// R = n, C = m
const int MaxRow = 1005, MaxCol = 1005;
int R, C;
vector<int> a[MaxRow], b[MaxCol];
int matched[MaxRow], mark[MaxCol], mate[MaxCol];


void addEdge(int r, int c)
{
    a[r].push_back(c);
    b[c].push_back(r);
}

bool dfs(int v)
{
    if (v < 0)
        return true;
    
    for (int node : a[v])
    {
        if (!mark[node]++ && dfs(mate[node]))
        {
            mate[node] = v;
            matched[v] = 1;
            return true;
        }
    }
    
    return false;
}

void set_mark()
{
    memset(matched, 0, sizeof matched);
    memset(mate, -1, sizeof mate);
    memset(mark, 0, sizeof mark);
    
    for (int i = 0; i < R; ++i)
    {
        for (int node : a[i])
        {
            if (mate[node] < 0)
            {
                mate[node] = i;
                matched[i] = 1;
                break;
            }
        }
    }
    
    for (int i = 0; i < R; ++i)
    {
        if (!matched[i] && dfs(i))
            memset(mark, 0, sizeof mark);
    }
    
    for (int i = 0; i < R; ++i)
    {
        if (!matched[i])
            dfs(i);
    }
}


void vertex_cover(vector<int> &p1, vector<int> &p2)
{
    set_mark();
    p1.clear();
    p2.clear();
    
    for (int i = 0; i < C; ++i)
    {
        if (mate[i] >= 0)
        {
            if (mark[i])
                p2.push_back(i);
            else
                p1.push_back(mate[i]);
        }
    }
}

int main()
{
    int N;
    
    vector<int> rows, columns;
    
    while (cin >> R >> C >> N, R)
    {
        for (int i = 0; i < R; ++i)
            a[i].clear();
        for (int i = 0; i < C; ++i)
            b[i].clear();
        
        while (N--)
        {
            int r, c;
            cin >> r >> c;
            addEdge(r - 1, c - 1);
        }
        
        
        vertex_cover(rows, columns);
        
        cout << (rows.size() + columns.size());
        for (int rowNode : rows)
            cout << " r" << (rowNode + 1);
        for (int colNode : columns)
            cout << " c" << (colNode + 1);
        cout << '\n';
    }
}