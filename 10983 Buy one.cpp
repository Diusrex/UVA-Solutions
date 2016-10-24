#include <iostream>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

// 30 cities, 11 times 
#define MAXN 350
const int Inf = 1e9;

typedef struct{
  int v, cap, flow, cost;
} Edge;

vector<Edge> g[MAXN];
int pred[MAXN], maxcap[MAXN], S[MAXN];

/* Should only be used when know that the edge between the two nodes is only added once */
void addUniqueEdge(int u, int v, int cap, int cost){
  Edge e;
  e.cost = cost;
  
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

int maxflow(int n, int source, int sink, int maxCost){
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
	    if(S[e.v] || e.cost > maxCost) continue;
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
    for(inc = Inf, v = sink; v != source; v = pred[v])
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

inline int GetCity(int city, int day, int N)
{
    return city + day * N;
}


int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int N, D, M;
        cin >> N >> D >> M;
        const int TotalCityNodes = N * (D + 1);
        // Is the N
        const int Sink = TotalCityNodes - 1;
        const int Source = TotalCityNodes;
        const int TotalNodes = Source + 1;
        for (int i = 0; i < TotalNodes; ++i)
            g[i].clear();
        
        // Add edges for each city to the following day
        for (int d = 0; d < D; ++d)
        {
            for (int c = 0; c < N; ++c)
            {
                addUniqueEdge(GetCity(c, d, N), GetCity(c, d + 1, N), Inf, 0);
            }
        }
        
        set<int> unique_costs;
        // Possible all start in the correct city
        unique_costs.insert(0);
        // Read in flights
        while (M--)
        {
            int from, to, capacity, cost, day;
            cin >> from >> to >> capacity >> cost >> day;
            --from; --to;
            addUniqueEdge(GetCity(from, day, N), GetCity(to, day + 1, N), capacity, cost);
            unique_costs.insert(cost);
        }
        int totalParticipants = 0;
        // Add number participants at each city
        for (int i = 0; i < N; ++i)
        {
            int num;
            cin >> num;
            totalParticipants += num;
            addUniqueEdge(Source, i, num, 0);
        }
        
        const vector<int> costs(unique_costs.begin(), unique_costs.end());
        int start = 0, end = costs.size() - 1;
        while (start < end)
        {
            int middle = (start + end) / 2;
            if (maxflow(TotalNodes, Source, Sink, costs[middle]) == totalParticipants)
            {
                end = middle;
            }
            else
                start = middle + 1;
        }
        
        cout << "Case #" << t << ": ";
        if (start > end || maxflow(TotalNodes, Source, Sink, costs[start]) != totalParticipants)
            cout << "Impossible\n";
        else
            cout << costs[start] << '\n';
    }
}