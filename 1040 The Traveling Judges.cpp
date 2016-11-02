#include <iostream>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

const int MaxNumCities = 21;

struct NodeCost
{
    NodeCost(int node, int cost)
        : node(node), cost(cost)
        {}
    int node, cost;
    
    // Low cost first, low node first,
    // then, a lower parent
    bool operator<(const NodeCost& other) const
    {
        if (cost != other.cost)
            return cost > other.cost;
        return node > other.node;
    }
};

typedef pair<int, int> pii;

int N;
vector<pii> roads[MaxNumCities];

int bestCost;
int bestTravelledTo[MaxNumCities];

void GetCost(const bitset<MaxNumCities> allAllowed, int destination)
{
    priority_queue<NodeCost> frontier;
    
    frontier.push(NodeCost(destination, 0));
    
    int travelledTo[MaxNumCities];
    for (int i = 0; i < N; ++i)
        travelledTo[i] = -1;
    int cost[MaxNumCities];
    
    travelledTo[destination] = -2;
    
    int totalCost = 0;
    
    while (!frontier.empty())
    {
        NodeCost current = frontier.top();
        frontier.pop();
        
        if (cost[current.node] < current.cost)
            continue;
        
        // Added cost is just the cost from here to next
        if (current.node != destination)
        {
            totalCost += cost[current.node];
        }
        
        if (totalCost > bestCost)
            return;
        
        // Has already been included, can't be better
        cost[current.node] = 0;
        
        for (int i = 0; i < roads[current.node].size(); ++i)
        {
            int travelFrom = roads[current.node][i].first;
            if (!allAllowed[travelFrom])
                continue;
            
            int costTo = roads[current.node][i].second;
            if (travelledTo[travelFrom] == -1 || // Hasn't been travelled to
                cost[travelFrom] > costTo) // Cheaper to travel from here
            {
                travelledTo[travelFrom] = current.node;
                cost[travelFrom] = costTo;
                frontier.push(NodeCost(travelFrom, costTo));
            }
            // Ensure is lowest possible
            if (cost[travelFrom] == costTo)
                travelledTo[travelFrom] = min(travelledTo[travelFrom], current.node);
        }
    }
    
    
    if (totalCost < bestCost)
    {
        // Ensure it is valid - hit all nodes
        for (int i = 0; i < N; ++i)
            if (allAllowed[i] && travelledTo[i] == -1)
                return;
            
        
        bestCost = totalCost;
        for (int i = 0; i < N; ++i)
            bestTravelledTo[i] = travelledTo[i];
    }
}

void Solve(int node, const int destination, bitset<MaxNumCities> citiesAllowed, const bitset<MaxNumCities>& requiredCities)
{
    if (node == N)
        GetCost(citiesAllowed, destination);
    else if (requiredCities[node])
        Solve(node + 1, destination, citiesAllowed, requiredCities);
    else
    {
        citiesAllowed[node] = false;
        Solve(node + 1, destination, citiesAllowed, requiredCities);
        citiesAllowed[node] = true;
        Solve(node + 1, destination, citiesAllowed, requiredCities);
    }
}

int main()
{
    int T = 1;
    while (cin >> N, N != -1)
    {
        int destination, numRoads;
        cin >> destination >> numRoads;
        --destination;
        
        for (int i = 0; i < N; ++i)
            roads[i].clear();
        
        while (numRoads--)
        {
            int c1, c2, cost;
            cin >> c1 >> c2 >> cost;
            --c1;
            --c2;
            roads[c1].push_back(make_pair(c2, cost));
            roads[c2].push_back(make_pair(c1, cost));
        }
        int numJudges;
        cin >> numJudges;
        vector<int> judgeCities;
        bitset<MaxNumCities> requiredCities;
        while (numJudges--)
        {
            int city;
            cin >> city;
            --city;
            judgeCities.push_back(city);
            requiredCities[city] = true;
        }
        
        requiredCities[destination] = true;
        
        bestCost = 2e9;
        
        Solve(0, destination, requiredCities, requiredCities);
        
        cout << "Case " << T++ << ": distance = " << bestCost << '\n';
        for (int i = 0; i < judgeCities.size(); ++i)
        {
            int current = judgeCities[i];
            cout << "   ";
            while (current != destination)
            {
                cout << (current + 1) << '-';
                current = bestTravelledTo[current];
            }
            
            cout << (destination + 1) << '\n';
        }
        cout << '\n';
    }
}