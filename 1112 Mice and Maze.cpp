#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct Node
{
    Node(int pos, int dist)
        : pos(pos),
        dist(dist)
    {}
        
    int pos, dist;
    
    bool operator<(const Node & other) const
    {
        return dist > other.dist;
    }
};

bool expanded[105];
int distanceFrom[105];

// If == -1, not known
vector<Node> connectedTo[105];

int T;


void Dijkstras(int from)
{
    priority_queue<Node> nodes;
    
    nodes.emplace(from, 0);
    
    while (!nodes.empty())
    {
        Node node = nodes.top();
        nodes.pop();
        
        if (expanded[node.pos])
            continue;
        
        expanded[node.pos] = true;
        distanceFrom[node.pos] = node.dist;
        
        for (const auto &to : connectedTo[node.pos])
        {
            if (!expanded[to.pos])
            {
                if (to.dist + node.dist <= T)
                    nodes.emplace(to.pos, to.dist + node.dist);
            }
        }
    }
}


int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int N, from, M;
        cin >> N >> from >> T >> M;
        for (int i = 1; i <= N; ++i)
        {
            expanded[i] = false;
            distanceFrom[i] = T + 1;
            connectedTo[i].clear();
        }
        
        while (M--)
        {
            int f, t, c;
            cin >> f >> t >> c;
            connectedTo[t].emplace_back(f, c); // Store them in opposite order
        }
        
        Dijkstras(from);
        
        int c = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (distanceFrom[i] <= T)
                ++c;
        }
        cout << c << '\n';
        if (cases)
            cout << '\n';
    }
}