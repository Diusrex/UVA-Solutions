#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<vector<int> > dependsOn(26);
vector<int> cost(26);
vector<int> bestTime(26);
vector<bool> checked(26);

int CalculateCost(int pos)
{
    int &time = bestTime[pos];
    if (!checked[pos])
    {
        time = 0;
        for (int i = 0; i < dependsOn[pos].size(); ++i)
            time = max(time, CalculateCost(dependsOn[pos][i]));
        
        time += cost[pos];
        checked[pos] = true;
    }
    
    return time;
}

int main()
{
    int T;
    cin >> T;
    
    // Need to remove the two blank lines
    cin.ignore();
    cin.ignore();
    
    string sep = "";
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        // Clear old data
        for (int i = 0; i < 26; ++i)
        {
            cost[i] = 0;
            dependsOn[i].clear();
            checked[i] = false;
        }
        
        string line;
        char task;
        string dependencies;
        
        while (getline(cin, line) && line != "")
        {
            int pos = line[0] - 'A';
            stringstream ss(line);
            ss >> task >> cost[pos];
            
            if (ss >> dependencies)
            {
                for (int i = 0; i < dependencies.size(); ++i)
                    dependsOn[pos].push_back(dependencies[i] - 'A');
            }
        }
        
        for (int i = 0; i < 26; ++i)
        {
            CalculateCost(i);
        }
        
        int worstTime = 0;
        for (int i = 0; i < 26; ++i)
            worstTime = max(worstTime, bestTime[i]);
        
        cout << worstTime << '\n';
    }
}