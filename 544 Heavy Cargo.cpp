#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

const int NO_PATH = -1;

map<string, int> nameToPos;

int GetSpot(const string &name, int &numNamesAdded)
{
    if (nameToPos.find(name) == nameToPos.end())
    {
        nameToPos[name] = numNamesAdded++;
        return numNamesAdded - 1;
    }
    else
    {
        return nameToPos.find(name)->second;
    }
}

int main()
{
    int n, r;
    
    int T = 1;
    while (cin >> n >> r, n)
    {
        int numAdded = 0;
        nameToPos.clear();
        vector<vector<int> > bestWeight(n, vector<int>(n, NO_PATH));
        
        string firstName, secondName;
        int first, second, weight;
        for (int i = 0; i < r; ++i)
        {
            cin >> firstName >> secondName >> weight;
            first = GetSpot(firstName, numAdded);
            second = GetSpot(secondName, numAdded);
            bestWeight[first][second] = weight;
            bestWeight[second][first] = weight;
        }
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (bestWeight[i][j] < min(bestWeight[i][k], bestWeight[k][j]))
                        bestWeight[i][j] = min(bestWeight[i][k], bestWeight[k][j]);
        
        
        cin >> firstName >> secondName;
        first = GetSpot(firstName, numAdded);
        second = GetSpot(secondName, numAdded);
        
        cout << "Scenario #" << T++ << "\n" << bestWeight[first][second] << " tons\n\n";
    }
}