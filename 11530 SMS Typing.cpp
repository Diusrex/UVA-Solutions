#include <string>
#include <iostream>

using namespace std;

int main()
{
    int costs[128], cost(1);
    
    for (int i = 'a'; i <= 'z'; ++i, ++cost)
    {
        costs[i] = cost;
        
        if (cost > 2 && i != 'r' && i != 'y')
            cost = 0;
    }
    costs[' '] = 1;
    
    int T;
    
    cin >> T;
    
    
    string line;
    getline(cin, line); // Get rid of rest of first line
    for (int t = 1; t <= T; ++t)
    {
        getline(cin, line);
        int totalCost = 0;
        
        for (string::const_iterator iter = line.begin(); iter != line.end(); ++iter)
            totalCost += costs[*iter];
        
        cout << "Case #" << t << ": " << totalCost << '\n';
    }
}