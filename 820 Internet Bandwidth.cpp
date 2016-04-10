#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


/*
  Author: Zachary Friggstad

  Edmonds-Karp algorithm for computing maximum flows.
  Runs in O(|V| * |E|^2) time in the worst case, but likely much faster in practice.

  To use:
  Clear g[v] for each vertex 0 <= v < n before reading any edges.

  For each directed edge (u,v) with capacity c
    call add_edge(u, v, c)

  If the graph is undirected and (u,v) is an undirected edge with capacity c,
    call both add_edge(u, v, c) and add_edge(v, u, c)

  max_flow(s, t, n) where s is the source, t is the sink, and n is the number of nodes
    will return the value of the maximum flow

  Notes:
   g is an adjacency list representation that includes all edges of the graph and their residual pairs

   g[v][i].r is a boolean that is false if g[v][i] is an edge of the original graph, and is true of
   g[v][i] is a residual edgea
   
   After computing the max flow, the flow across an edge g[v][i] with g[v][i].r == false is exactly
   g[g[v][i].v][g[v][i].i].c (the capacity of the residual pair)

   After computing the max flow, a min cut is the set {v : pre[v] != -1}.
   
 To do:
   Make the references to residual edges cleaner: with a pointer.
*/

#define INF 100000000000ll
#define MAXN 105


typedef long long LL;

struct Edge {
  int u, v, i;
  LL c;
  bool r;
  Edge(int uu = 0, int vv = 0, LL cc = 0, int ii = 0, bool rr = false) :
    u(uu), v(vv), c(cc), i(ii), r(rr) {}
};

vector<Edge> g[MAXN];
int pre[MAXN];

void add_edge(int u, int v, LL c) {
  g[u].push_back(Edge(u, v, c, g[v].size(), false));
  g[v].push_back(Edge(v, u, 0, g[u].size()-1, true));
}

LL augment(int s, int t, int n) {
  queue<int> q;
  for (int i = 0; i < n; ++i) pre[i] = -1;
  pre[s] = -2;
  q.push(s);

  while (!q.empty() && pre[t] == -1) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < g[curr].size(); ++i) {
      Edge succ = g[curr][i];
      if (pre[succ.v] == -1 && succ.c > 0) {
        pre[succ.v] = succ.i;
        q.push(succ.v);
      }
    }
  }

  if (pre[t] == -1) return 0;

  LL val = INF;
  int v = t;
  while (v != s) {
    int u = g[v][pre[v]].v;
    val = min(val, g[u][g[v][pre[v]].i].c);
    v = u;
  }

  v = t;
  while (v != s) {
    int u = g[v][pre[v]].v;
    g[v][pre[v]].c += val;
    g[u][g[v][pre[v]].i].c -= val;
    v = u;
  }

  return val;
}

LL max_flow(int s, int t, int n) {
  LL flow = 0, aug;

  while ((aug = augment(s, t, n))) flow += aug;

  return flow;
}

void Reset(int n)
{
    for (int i = 0; i < n; ++i)
        g[i].clear();
}

int main()
{
    int n;
    int T = 1;
    
    while (cin >> n, n)
    {
        Reset(n);
        int s, t, connections;
        cin >> s >> t >> connections;
        --s;
        --t;
        
        while (connections--)
        {
            int u, v, c;
            cin >> u >> v >> c;
            --u; --v;
            
            add_edge(u, v, c);
            add_edge(v, u, c);
        }
        
        cout << "Network " << T++ << '\n';
        cout << "The bandwidth is " << max_flow(s, t, n) << ".\n\n";
    }
}

