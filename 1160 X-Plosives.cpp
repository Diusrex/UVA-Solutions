#include <iostream>
#include <vector>

using namespace std;

const int NUM_NODES = 100005;
const int NO_PARENT = -1;

vector<int> connections[NUM_NODES];

bool IsPath(int current, int parent, int target)
{
    if (current == target)
        return true;
    
    for (int i = 0; i < connections[current].size(); ++i)
    {
        if (connections[current][i] != parent && IsPath(connections[current][i], current, target))
            return true;
    }
    
    return false;
}

int main()
{
    int first, second;
    
    while (cin >> first >> second)
    {
        // Clear old connections
        for (int i = 0; i < NUM_NODES; ++i)
            connections[i].clear();
        
        bool doubleConnected = (first == second);
        if (first != second)
        {
            connections[first].push_back(second);
            connections[second].push_back(first);
        }
        
        int numIgnored = 0;
        
        while (cin >> first, first != -1)
        {
            cin >> second;
            
            if (first == second)
            {
                if (doubleConnected)
                    ++numIgnored;
                
                doubleConnected = true;
            }
            
            else if (!IsPath(first, NO_PARENT, second))
            {
                connections[first].push_back(second);
                connections[second].push_back(first);
            }
            
            else
                ++numIgnored;
        }
        
        cout << numIgnored << '\n';
    }
}
// Basically looking to see if there is a path back to current node
    // That doesn't involve duplicates
    // So can always accept nodes of type A A
    // Double sided