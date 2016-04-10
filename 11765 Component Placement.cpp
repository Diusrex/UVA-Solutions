#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// General idea of the conversion to max flow problem

// Two layers they can be placed on, top or bottom
// So have from source to each node be the top cost, and from node to sink be bottom cost
    // Or placement
// If nodes would be placed on the same side, their bottleneck will be the same side (from source, or to sink),
    // so there would be no flow along their connection
// If nodes would be placed on different sides, their bottleneck will be different sides,
    // so there will be flow along the the connection between them, which would be the cost for different

/*
  Edmonds-Karp algorithm for computing maximum flows.
  Runs in O(|V| * |E|^2) time in the worst case, but likely much faster in practice.
  
  Author: Zachary Friggstad

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
#define MAXN 210

const int compStart = 26;
const int source = 36;
const int sink = 37;
const int numNodes = 38;

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

int topCost[201];
int bottomCost[201];

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        
        int source = N, sink = source + 1, totalNodes = sink + 1;
        // Reset data
        Reset(totalNodes);
        
        // Read top cost
        for (int i = 0; i < N; ++i)
            cin >> topCost[i];
        
        for (int j = 0; j < N; ++j)
            cin >> bottomCost[j];
        
        for (int i = 0; i < N; ++i)
        {
            int p;
            cin >> p;
            // Model where:
            // A node on the top can send infinite to the sink
            // A node on the bottom gets infinite from the source
            // The connection to the other main node will be their top/bottom cost
            // A node that can be placed in either will use the top and bottom costs
            if (p == 1) // Top only
            {
                add_edge(source, i, topCost[i]);
                add_edge(i, sink, INF);
            }
            else if (p == -1) // Bottom only
            {
                add_edge(source, i, INF);
                add_edge(i, sink, bottomCost[i]);
            }
            
            else // Can be placed on either
            {
                add_edge(source, i, topCost[i]);
                add_edge(i, sink, bottomCost[i]);
            }
        }
        
        // Read the connections, and link the nodes
        while (M--)
        {
            int p, q, r;
            cin >> p >> q >> r;
            --p; --q;
            
            add_edge(p, q, r);
            add_edge(q, p, r);
        }
        
        cout << max_flow(source, sink, totalNodes) << '\n';
    }
}

