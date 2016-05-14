#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>


// Note this is C++11
// Had had problems with parsing before switching to stringstream

using namespace std;


int N;
vector<int> connected[305];

bool reached[305];
int parent[305];

void bfs(int start, int target)
{
    if (start == target)
    {
        cout << start << '\n';
        return;
    }
    
    for (int i = 0; i < 305; ++i)
        parent[i] = -1;
    
    queue<int> currentQ;
    
    currentQ.push(start);
    while (!currentQ.empty() && parent[target] == -1)
    {
        int current = currentQ.front();
        currentQ.pop();
        
        for (int next : connected[current])
        {
            if (parent[next] == -1)
            {
                parent[next] = current;
                currentQ.push(next);
            }
        }
    }
    
    if (parent[target] == -1)
        cout << "connection impossible\n";
    
    else
    {
        stack<int> reversed;
        int n = target;
        while (n != start)
        {
            reversed.push(n);
            n = parent[n];
        }
        
        cout << start;
        while (!reversed.empty())
        {
            int top = reversed.top(); reversed.pop();
            cout << ' ' << top;
        }
        
        cout << '\n';
    }
}

int main()
{
    char garbage;
    string line;
    
    while (cin >> N && N)
    {
        for (int i = 0; i < 305; ++i)
        {
            connected[i].clear();
        }
        
        for (int i = 0; i < N; ++i)
        {
            int router;
            cin >> router;
            
            getline(cin, line);
            
            stringstream ss(line);
            int connectedTo;
            while (ss >> garbage >> connectedTo)
            {
                connected[router].push_back(connectedTo);
            }
        }
                
        int m;
        cin >> m;
        
        cout << "-----\n";
        
        while (m--)
        {
            int start, target;
            cin >> start >> target;
            
            bfs(start, target);
        }
    }
}