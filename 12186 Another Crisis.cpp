#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MaxNum = 100005;

int N, T;

vector<int> children[MaxNum];

int DetermineNumberNeeded(int node)
{
    if (children[node].size() == 0)
        return 1;
    
    // Automatically sorted
    multiset<int> costs;
    for (int i = 0; i < children[node].size(); ++i)
        costs.insert(DetermineNumberNeeded(children[node][i]));
    
    int numNeeded = T * children[node].size(), cost = 0, includedChildren = 0;
    
    // T is already multiplied by 100
    for (multiset<int>::iterator iter = costs.begin(); includedChildren < numNeeded; includedChildren += 100, ++iter)
    {
        cost += *iter;
    }
    
    return cost;
}

int main()
{
    while (cin >> N >> T, N)
    {
        for (int i = 0; i <= N; ++i)
            children[i].clear();
        
        // Skip owner
        for (int i = 1; i <= N; ++i)
        {
            int boss;
            cin >> boss;
            
            children[boss].push_back(i);
        }
        
        // Determine for the owner
        cout << DetermineNumberNeeded(0) << '\n';
    }
}