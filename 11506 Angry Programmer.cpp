#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

// Graph layout:
    // Each machine uses two nodes -> One in, one out
    // They are connected based on the machines cost to destroy
    // When machines U and V are connected, will do:
        // addEdge(Uout, Vin, cap)
        // addEdge(Vout, Uin, cap)

#define MAXN 105

typedef struct{
  int v, cap, flow;
} Edge;

vector<Edge> g[MAXN];
int pred[MAXN], maxcap[MAXN], S[MAXN];

// This code is from the U of A Programming Club Code Archive

/* Should only be used when know that the edge between the two nodes is only added once */
void addUniqueEdge(int u, int v, int cap){
  Edge e;

  /* Add edge u->v */
  e.v = v; e.cap = cap; e.flow = 0;  
  g[u].push_back(e);                 
  
  /* Add reverse edge v->u */
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
    for (i = 0; i < n; ++i)
        S[i] = 0;
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
    int M, W;
    
    while (cin >> M >> W, M)
    {
        // Clear existing edges
        for (int i = 1; i <= 2 * M; ++i)
            g[i].clear();
        
        // Since the numbering is from 1 to M
        const int inStart = 1, outOffset = M;
        for (int i = 0; i < M - 2; ++i)
        {
            int id, cost;
            cin >> id >> cost;
            
            // Add the cost to destroy the machine.
            addUniqueEdge(id, id + outOffset, cost);
            
        }
        
        while (W--)
        {
            int i, j, cost;
            cin >> i >> j >> cost;
            
            addUniqueEdge(i + outOffset, j, cost);
            addUniqueEdge(j + outOffset, i, cost);
        }
        
        
        // Want it from the out for boss (comp 1) to in of M comp
        cout << maxflow(M * 2 + 2, 1 + outOffset, M) << '\n';
    }
}
