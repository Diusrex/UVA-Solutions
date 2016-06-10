#include <iostream>
#include <queue>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

// Is C++11 since got lazy (didnt want to write constructor)

const double Eps = 1e-7;
inline bool LessThan(double lhs, double rhs)
{
    return lhs < rhs - Eps;
}

struct NodeCost
{
    int node;
    double cost;
    
    bool operator<(const NodeCost & other) const
    {
        return LessThan(other.cost, cost);
    }
};

// up to 200 subway stops, and the start/goal
const int MaxNumSpots = 205;
int N;

// Are the distances squared
vector<NodeCost> connections[MaxNumSpots];
double costs[MaxNumSpots];



int x[MaxNumSpots], y[MaxNumSpots];

// 40km/hr is 40 * 1hr/60min * 1000m/km
const double WalkSpeed = (10.0 / 60.0 * 1000.0), TrainSpeed = (40.0 / 60.0 * 1000.0);


inline double GetCost(int i, int j)
{
    int xDiff = x[i] - x[j], yDiff = y[i] - y[j];
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

double Dijkstras(int start, int goal)
{
    priority_queue<NodeCost> q;
    q.push(NodeCost{start, 0});
    costs[start] = 0;
    
    while (true)
    {
        NodeCost next = q.top(); q.pop();
        
        if (next.node == goal)
            return next.cost;
        
        if (LessThan(costs[next.node], next.cost))
            continue;
        
        for (NodeCost connected : connections[next.node])
        {
            if (LessThan(next.cost + connected.cost, costs[connected.node]))
            {
                costs[connected.node] = next.cost + connected.cost;
                q.push(NodeCost{connected.node, next.cost + connected.cost});
            }
        }
        
    }
}

int main()
{
    const int start = 0, goal = 1;
    
    int T;
    cin >> T;
    string junk, sep = "";
    
    while (T--)
    {
        connections[start].clear(); connections[goal].clear();
        
        cin >> x[start] >> y[start] >> x[goal] >> y[goal];
        double cost = GetCost(start, goal) / WalkSpeed;
        
        connections[start].push_back(NodeCost{goal, cost});
        connections[goal].push_back(NodeCost{start, cost});
        
        N = 2;
        
        while (getline(cin, junk), isdigit(cin.peek()))
        {
            int subwayStart = N;
            
            while (cin >> x[N] >> y[N], x[N] != -1)
            {
                int current = N;
                connections[current].clear();
                ++N;
                
                int stopAt = current - 1;
                // Connect to previous in rail
                if (current != subwayStart)
                {
                    cost = GetCost(current, current - 1) / TrainSpeed;
                    connections[current].push_back(NodeCost{current - 1, cost});
                    connections[current - 1].push_back(NodeCost{current, cost});
                }
                else
                    stopAt = subwayStart;
                
                // Connect to all previous nodes
                for (int i = 0; i < stopAt; ++i)
                {
                    cost = GetCost(current, i) / WalkSpeed;
                    connections[current].push_back(NodeCost{i, cost});
                    connections[i].push_back(NodeCost{current, cost});
                }
            }
            
        }
        for (int i = 0; i < N + 2; ++i)
            costs[i] = numeric_limits<long long>::max();
        
        cout << fixed << setprecision(0) << sep << Dijkstras(start, goal) << '\n';
        sep = "\n";
    }
}
