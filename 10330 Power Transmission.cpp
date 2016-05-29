#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;


// Graph_Theory: Maximum Flow in a directed graph
// Code from the U of A programming club code archive

// 100 in nodes, 100 out nodes, source, sink
#define MAXN 205

typedef struct{
  int v, cap, flow;
} Edge;

vector<Edge> g[MAXN];
int pred[MAXN], maxcap[MAXN], S[MAXN];

void addEdge(int u, int v, int cap){
  size_t i; Edge e;

  for(i = 0; i < g[u].size(); i++)    /* Add cap if edge exists */
    if(g[u][i].v == v){
      g[u][i].cap += cap;
      return;
    }

  e.v = v; e.cap = cap; e.flow = 0;  
  g[u].push_back(e);                 /* Add edge u->v */
  
  for(i = 0; i < g[v].size(); i++)   /* Add dummy reverse edge */
    if(g[v][i].v == u) return;
  
  e.v = u; e.cap = 0;
  g[v].push_back(e);
}

Edge *getEdge(int u, int v){
  for(size_t i = 0; i < g[u].size(); i++)
    if(g[u][i].v == v) return &g[u][i];
  return 0;
}

int maxflow(int n, int source, int sink){
  vector<int> q; int i, v, flow, inc;
  size_t j; Edge *e1, *e2;

  for(i = 0; i < n; i++)
    for(j = 0; j < g[i].size(); j++)
      g[i][j].flow = 0;                 /* Clear all flows */
  
  flow = 0;

  while(1){                 /* BFS to find augmenting path */
    memset(S, 0, sizeof(S));
    S[source] = 1;
    q.clear(); q.push_back(source);
    for(i = 0; i < (int)q.size(); i++){
      v = q[i];
      if(v == sink) break;
      for(j = 0; j < g[v].size(); j++){
	Edge e = g[v][j];
	if(S[e.v]) continue;
	if(e.cap && e.flow < e.cap){
	  q.push_back(e.v); S[e.v] = 1; pred[e.v] = v;
	  maxcap[e.v] = e.cap - e.flow;
	} else {
	  e1 = getEdge(e.v, v);
	  if(e1 && e1->cap && e1->flow > 0){
	    q.push_back(e.v); S[e.v] = 1; pred[e.v] = v;
	    maxcap[e.v] = e1->flow;
	  }
	}
      }
    }
    if(v != sink) break;  /* No more augmenting paths */
    
    /* Calculate flow */
    for(inc = INT_MAX, v = sink; v != source; v = pred[v])
      inc = min(inc, maxcap[v]);
    flow += inc;
    
    /* Update flow */
    for(v = sink; v != source; v = pred[v]){
      e1 = getEdge(pred[v], v);
      e2 = getEdge(v, pred[v]);
      
      if(e1 && e1->cap)      e1->flow += inc;
      else if(e2 && e2->cap) e2->flow -= inc;

      if(e1 && e2 && e1->flow && e2->flow){
	if(e1->flow > e2->flow){
	  e1->flow -= e2->flow;
	  e2->flow = 0;
	} else {
	  e2->flow -= e1->flow;
	  e1->flow = 0;
	}
      }
    }
  }
  return flow;
}

int main()
{
    int N;
    while (cin >> N)
    {
        int source = N * 2, sink = source + 1;
        for (int i = 0; i < 2 * N + 2; ++i)
        {
            g[i].clear();
        }
        
        for (int i = 0; i < N; ++i)
        {
            int flow;
            cin >> flow;
            addEdge(i, i + N, flow);
        }
        int M;
        cin >> M;
        
        
        while (M--)
        {
            int i, j, flow;
            cin >> i >> j >> flow;
            addEdge(i + N - 1, j - 1, flow);
        }
        
        int B, D;
        cin >> B >> D;
        
        while (B--)
        {
            int i;
            cin >> i;
            --i;
            // The max flow into the node would be the max flow it can handles
            addEdge(source, i, g[i][0].cap);
        }
        
        while (D--)
        {
            int i;
            cin >> i;
            --i;
            // The max flow into the node would be the max flow it can handles
            addEdge(i + N, sink, g[i][0].cap);
        }
        
        cout << maxflow(sink + 1, source, sink) << '\n';
    }
}