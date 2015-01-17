#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > connections;
const int UNCOLORED = -1;


bool IsBicolored(int node, int color, vector<int>& colors)
{
    if (colors[node] == UNCOLORED)
    {
        colors[node] = color;
        
        for (int i = 0; i < connections[node].size(); ++i)
            if (!IsBicolored(connections[node][i], 1 - color, colors))
                return false;
        
    }
    
    else if (colors[node] != color)
        return false;
    
    return true;
}
int main()
{
    int n;
    
    while (cin >> n, n)
    {
        connections.assign(n, vector<int>());
        
        int l;
        cin >> l;
        
        while (l--)
        {
            int start, end;
            cin >> start >> end;
            connections[start].push_back(end);
            connections[end].push_back(start);
        }
        
        vector<int> color(n, UNCOLORED);
        if (IsBicolored(0, 0, color))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
}