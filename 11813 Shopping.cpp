#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int HOME = 0;

// Find the cost to go from each store each other node
    // Bi-directional roads, so don't need to check for the last store

// Then, find the best path among the 10 nodes, including going from/to store
    // This would behave as the travelling salesman problem (~n!)

int S;

vector<vector<pair<int, long long> > > pathToCost;
vector<vector<long long> > costAmongStores;
vector<long long> costToNodeFromCurrent;

class Comparison
{
public:
  bool operator() (const pair<int, int>& lhs, const pair<int, int>&rhs) const
  {
    return lhs.second >= rhs.second;
  }
};

void Dijkstras(vector<int> & storePos, int N)
{
    priority_queue<pair<int, int>, std::vector<pair<int, int> >, Comparison> q;
    costAmongStores.assign(S, vector<long long>(S));
    costToNodeFromCurrent.resize(N);
    
    for (int i = 0; i < S - 1; ++i)
    {
        for (int j = 0; j < N; ++j)
            costToNodeFromCurrent[j] = -1;
        
        q.push(pair<int, int>(storePos[i], 0));
        
        while (!q.empty())
        {
            pair<int, int> top = q.top();
            
            int &node = top.first;
            int &cost = top.second;
            
            q.pop();
            
            if (cost > costToNodeFromCurrent[node]
                && costToNodeFromCurrent[node] != -1)
                continue;
            
            for (int j = 0; j < pathToCost[node].size(); ++j)
            {
                const pair<int, int>& current = pathToCost[node][j];
                
                if (cost + current.second < costToNodeFromCurrent[current.first]
                    || costToNodeFromCurrent[current.first] == -1)
                {
                    costToNodeFromCurrent[current.first] = cost + current.second;
                    q.push(pair<int, int>(current.first, cost + current.second));
                }
            }
        }
        
        for (int j = i + 1; j < S; ++j)
        {
            int otherPos = storePos[j];
            costAmongStores[i][j] = costToNodeFromCurrent[otherPos];
            costAmongStores[j][i] = costToNodeFromCurrent[otherPos];
        }
    }
}

int finished;

void Travel(int currentNode, long long cost, int travelledBits, long long & best)
{
    if (travelledBits == finished)
    {
        if (cost + costAmongStores[currentNode][HOME] < best)
            best = cost + costAmongStores[currentNode][HOME];
        
        return;
    }
    
    for (int i = 1, bit = 2; i < S; ++i, bit <<= 1)
    {
        if (!(bit & travelledBits) // Haven't added this yet
            && cost + costAmongStores[currentNode][i] < best)
            Travel(i, cost + costAmongStores[currentNode][i], travelledBits | bit, best);
    }
}



int main()
{
    int T;
    cin >> T;
    vector<int> storePos;
    
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        
        pathToCost.assign(N, vector<pair<int, long long> >());
        
        int X, Y, D;
        
        while (M--)
        {
            cin >> X >> Y >> D;
            pathToCost[X].push_back(pair<int, long long>(Y, D));
            pathToCost[Y].push_back(pair<int, long long>(X, D));
        }
        
        cin >> S;
        ++S;
        
        storePos.resize(S);
        storePos[0] = 0;
        
        finished = 1;
        for (int i = 1; i < S; ++i)
        {
            cin >> storePos[i];
            finished = 1 | (finished << 1);
        }
        
        Dijkstras(storePos, N);
        
        long long bestCost = costAmongStores[S - 1][0];
        
        for (int i = 0; i < S - 1; ++i)
        {
            bestCost += costAmongStores[i][i + 1];
        }
        
        Travel(0, 0, 1, bestCost);
        
        cout << bestCost << '\n';
    }
}