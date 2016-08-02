#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MaxN = 105;

// From U of A Programming Club Code Archive, maxflow_v2
struct Edge {
  int u, v, c;
};

// First N are input, second N are output
int F[2 * MaxN][2 * MaxN];

int maxFlow(int n, int s, int t, const vector<Edge> &M)
{
  int u, v, c, oh, min, df, flow, H[n], E[n], T[n], C[n][n];
  vector<Edge>::const_iterator m;
  list<int> N;
  list<int>::iterator cur;
  vector<int> R[n];
  vector<int>::iterator r;

  for (u = 0; u < n; u++) {
    E[u] = H[u] = T[u] = 0;
    R[u].clear();
    for (v = 0; v < n; v++)
      C[u][v] = F[u][v] = 0;
  }
  
  for (m = M.begin(); m != M.end(); m++) {
    u = m->u;
    v = m->v;
    c = m->c;
    if (c && !C[u][v] && !C[v][u]) {
      R[u].push_back(v);
      R[v].push_back(u);
    }
    C[u][v] += c;
  }

  H[s] = n;

  for (r = R[s].begin(); r != R[s].end(); r++) {
    v = *r;
    F[s][v] =  C[s][v];
    F[v][s] = -C[s][v];
    E[v]  = C[s][v];
    E[s] -= C[s][v];
  }

  N.clear();
  for (u = 0; u < n; u++)
    if ((u != s) && (u != t))
      N.push_back(u);

  for (cur = N.begin(); cur != N.end(); cur++) {
    u = *cur;
    oh = H[u];
    
    while (E[u] > 0)
      if (T[u] >= (int)R[u].size()) {
	min = 10000000;
	for (r = R[u].begin(); r != R[u].end(); r++) {
	  v = *r;
	  if ((C[u][v] - F[u][v] > 0) && (H[v] < min))
	    min = H[v];
	}
	H[u] = 1 + min;
	T[u] = 0;
      }
      else {
	v = R[u][T[u]];
      
	if ((C[u][v] - F[u][v] > 0) && (H[u] == H[v]+1)) {
	  df = C[u][v] - F[u][v];
	  if (df > E[u])
	    df = E[u];

	  F[u][v] += df;
	  F[v][u]  = -F[u][v];
	  E[u] -= df;
	  E[v] += df;
	}
	else
	  T[u]++;
      }

    if (H[u] > oh)
      N.splice(N.begin(), N, cur);
  }
  
  flow = 0;

  for (r = R[s].begin(); r != R[s].end(); r++)
    flow += F[s][*r];

  return flow;
}

int x[MaxN], y[MaxN];

int GetSquaredDist(int i, int j)
{
    int xDiff = x[i] - x[j], yDiff = y[i] - y[j];
    return xDiff * xDiff + yDiff * yDiff;
}

int main()
{
    int T;
    cin >> T;
    vector<Edge> edges;
    while (T--)
    {
        edges.clear();
        int N;
        double jump_dist;
        int num_penguins = 0;
        cin >> N >> jump_dist;
        const int source = N * 2, sink = source + 1;
        const double jump_dist_squared = jump_dist * jump_dist;
        Edge tempEdge;
        for (int i = 0; i < N; ++i)
        {
            int maxOut;
            // Edge from source to this guy first
            cin >> x[i] >> y[i] >> tempEdge.c >> maxOut;
            num_penguins += tempEdge.c;
            
            // If it starts off with penguins
            if (tempEdge.c)
            {
                tempEdge.u = source;
                tempEdge.v = i;
                edges.push_back(tempEdge);
            }
            
            // Edge from in for this node to out for node
            tempEdge.u = i;
            tempEdge.v = i + N;
            tempEdge.c = maxOut;
            edges.push_back(tempEdge);
            
            // Connect to all other nodes
            // Using a capacity of 205 is higher than any piece can handle jumping off anyway
            tempEdge.c = 1e8;
            for (int j = 0; j < i; ++j)
            {
                if (GetSquaredDist(i, j) <= jump_dist_squared)
                {
                    tempEdge.u = i + N;
                    tempEdge.v = j;
                    edges.push_back(tempEdge);
                    
                    tempEdge.u = j + N;
                    tempEdge.v = i;
                    edges.push_back(tempEdge);
                }
            }
        }
        
        string sep = "";
        // As of now, no node is connected to sink
        for (int i = 0; i < N; ++i)
        {
            // Try connecting node i to sink, see if it has a flow of all penguins
            // Connect the input directly though, to avoid having issues with jumping off limit
            tempEdge.u = i;
            tempEdge.v = sink;
            edges.push_back(tempEdge);
            if (maxFlow(sink + 1, source, sink, edges) == num_penguins)
            {
                cout << sep << i;
                sep = " ";
            }
            edges.pop_back();
            
        }
        
        if (sep.empty())
            cout << "-1\n";
        else
            cout << '\n';
    }
}