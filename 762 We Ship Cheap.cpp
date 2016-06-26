#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<vector<int> > connections;
vector<int> cameFrom;
map<string, int> nameToInt;
map<int, string> intToName;

void PrintPath(int node)
{
    if (cameFrom[node] >= 0)
    {
        PrintPath(cameFrom[node]);
        cout << intToName[cameFrom[node]] << ' ' << intToName[node] << '\n';
    }
}

void FindPath(int start, int goal)
{
    cameFrom.assign(connections.size(), -1);
    cameFrom[start] = -2;
    queue<int> nodes;
    nodes.push(start);
    
    while (!nodes.empty())
    {
        int current = nodes.front();
        nodes.pop();
        if (current == goal)
        {
            PrintPath(current);
            return;
        }
        
        for (int i = 0; i < connections[current].size(); ++i)
        {
            int next = connections[current][i];
            if (cameFrom[next] == -1)
            {
                nodes.push(next);
                cameFrom[next] = current;
            }
        }
    }
    
    cout << "No route\n";
}

int GetNextIndex()
{
    string name;
    cin >> name;
    if (nameToInt.find(name) == nameToInt.end())
    {
        int index = nameToInt.size();
        nameToInt[name] = index;
        
        intToName[index] = name;
        connections.push_back(vector<int>());
    }
    
    return nameToInt[name];
}

int main()
{
    string sep = "";
    
    int links;
    while (cin >> links)
    {
        cout << sep;
        sep = "\n";
        nameToInt.clear();
        connections.clear();
        
        while (links--)
        {
            int a = GetNextIndex();
            int b = GetNextIndex();
            
            connections[a].push_back(b);
            connections[b].push_back(a);
        }
        
        int start = GetNextIndex();
        int end = GetNextIndex();
        FindPath(start, end);
    }
}
