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
#define MAXN 40

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

void Reset()
{
    for (int i = 0; i <= sink; ++i)
        g[i].clear();
    
    // Edges for comp to sink
    for (int i = compStart; i < source; ++i)
    {
        add_edge(i, sink, 1);
    }
}

int ParseLine(const string &line)
{
    int app = line[0] - 'A';
    int num = line[1] - '0';
    
    add_edge(source, app, num);
    
    for (int i = 3; line[i] != ';'; ++i)
    {
        add_edge(app, compStart + line[i] - '0', 1);
    }
    
    return num;
}

int main()
{
    string line;
    
    while (getline(cin, line))
    {
        // 0 - 25 nodes are for applications
        // 26 - 35 nodes are for computers
        // 36 is source, 37 is sink
        
        // Resetting data
        Reset();
        
        int count = ParseLine(line);
        while (getline(cin, line) && line != "")
        {
            count += ParseLine(line);
        }
        
        
        int maxFlow = max_flow(source, sink, numNodes);
        
        if (count != maxFlow)
        {
            cout << "!\n";
        }
        else
        {
            // travel back from each computer
            // Know the first edge for it is for its connection to sink
            // For edge, if capacity is 0, then it is used
            for (int i = 0; i < 10; ++i)
            {
                int comp = i + compStart;
                if (g[comp][0].c)
                {
                    cout << '_';
                }
                else
                {
                    // Know it is connected to an application
                    // Find which using the residual edge, which will be 1 if it is connected
                    int i;
                    for (i = 1; !g[comp][i].c; ++i)
                        ;
                    
                    cout << (char)('A' + g[comp][i].v);
                }
            }
            cout << '\n';
        }
    }
}