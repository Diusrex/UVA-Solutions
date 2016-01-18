#include <iostream>
#include <vector>

using namespace std;

const int First = 0, Second = 1, Unset = 2;

// [1, b+c]
int color[2005];
vector<int> whatCanSee[2005];
bool sumPossible[1005];

// Only call when can get this color
bool Partition(int node, int currentGroup, int &currentGroupCount, int &otherGroupCount)
{
    color[node] = currentGroup;
    ++currentGroupCount;
    
    for (int i = 0; i < whatCanSee[node].size(); ++i)
    {
        int other = whatCanSee[node][i];
        
        if (color[other] == Unset)
        {
            if (!Partition(other, 1-currentGroup, otherGroupCount, currentGroupCount))
                return false;
        }
        
        else if (color[other] == currentGroup)
            return false;
    }
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int a, c, b;
        
        cin >> b >> c >> a;
        for (int i = 1; i <= b + c; ++i)
        {
            color[i] = Unset;
            whatCanSee[i].clear();
        }
        
        int largest = max(b, c);
        
        sumPossible[0] = true;
        for (int i = 1; i <= largest; ++i)
            sumPossible[i] = false;
        
        while (a--)
        {
            int u, v;
            cin >> u >> v;
            whatCanSee[u].push_back(v);
            whatCanSee[v].push_back(u);
        }
        
        bool possible = true;
        
        for (int i = 1; i <= b + c && possible; ++i)
        {
            if (color[i] == Unset)
            {
                int first = 0, second = 0;
                possible = Partition(i, First, first, second);
                
                for (int i = largest - 1; i >= 0; --i)
                {
                    if (sumPossible[i])
                    {
                        sumPossible[i] = false;
                        
                        if (i + first <= largest)
                            sumPossible[i + first] = true;
                        if (i + second <= largest)
                            sumPossible[i + second] = true;
                    }
                }
            }
        }
        
        // The wanted sum can be made
        if (possible && sumPossible[b] && sumPossible[c])
            cout << "yes\n";
        else
            cout << "no\n";
    }
}