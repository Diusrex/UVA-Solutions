#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<int> components;
vector<vector<int> > paths;
vector<bool> reached;

void FormComponent(int node, int currentComponent)
{
    components[node] = currentComponent;
    
    for (int i = 0; i < paths[node].size(); ++i)
    {
        if (components[paths[node][i]] == -1)
            FormComponent(paths[node][i], currentComponent);
    }
}

void Search(int current)
{
    reached[current] = true;
    
    for (int i = 0; i < paths[current].size(); ++i)
    {
        if (!reached[paths[current][i]])
            Search(paths[current][i]);
    }
}

int main()
{
    int t = 1;
    string temp, other, sep = "";
    while (cin >> n, n)
    {
        cout << sep;
        sep = "\n";
        
        map<string, int> m;
        vector<string> order(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            m[temp] = i;
            order[i] = temp;
        }
        
        int R;
        cin >> R;
        
        paths.assign(n, vector<int>());
        
        while (R--)
        {
            cin >> temp >> other;
            int f = m[temp], s = m[other];
            paths[f].push_back(s);
            paths[s].push_back(f);
        }
        
        components.assign(n, -1);
        int numComponents = 0;
        for (int i = 0; i < n; ++i)
        {
            if (components[i] == -1)
                FormComponent(i, numComponents++);
        }
        
        vector<string> special;
        reached.resize(n);
        
        for (int i = 0; i < n; ++i)
        {
            if (paths[i].size() == 0)
                continue;
            
            int currentComponent = components[i];
            
            for (int j = 0; j < n; ++j)
                reached[j] = false;
            reached[i] = true;
            Search(paths[i][0]);
            
            for (int j = 0; j < n; ++j)
                if (!reached[j] && components[j] == currentComponent)
                {
                    special.push_back(order[i]);
                    break;
                }
        }
        
        sort(special.begin(), special.end());
        cout << "City map #" << t++ << ": " << special.size() << " camera(s) found\n";
        
        for (int i = 0; i < special.size(); ++i)
            cout << special[i] << '\n';
    }
}