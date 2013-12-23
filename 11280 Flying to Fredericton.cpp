#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int T;
    
    cin >> T;
    
    string separator = "";
    
    for (int t = 1; t <= T; ++t)
    {
        cout << separator;
        separator = "\n";
        
        int numCities;
        cin >> numCities;
        
        map<string, int> cityPos;
        
        string temp;
        
        for (int i = 0; i < numCities; ++i)
        {
            cin >> temp;
            cityPos[temp] = i;
        }

        
        vector<vector<long long> > costToFlyTo(numCities, vector<long long>(numCities, -1));
        
        
        int numFlights;
        
        cin >> numFlights;
        
        string temp2;
        
        for (int i = 0; i < numFlights; ++i)
        {
            long long cost;
            
            cin >> temp >> temp2 >> cost;
            
            int posF = cityPos[temp], posS = cityPos[temp2];
            
            if (costToFlyTo[posF][posS] == -1 || costToFlyTo[posF][posS] > cost)
                costToFlyTo[posF][posS] = cost;
        }
        
        
        vector<vector<long long> > costForNumFlights(numCities, vector<long long>(numCities, -1));
        costForNumFlights[0][0] = 0;
        
        for (int city = 0; city < numCities - 1; ++city)
        {
            // There are at most numCities flights (because 0 is crossed off), but will check for flightNum + 1
            for (int flightNum = 0; flightNum < numCities - 1; ++flightNum)
            {
                for (int flyTo = city + 1; flyTo < numCities; ++flyTo)
                {
                    if (costToFlyTo[city][flyTo] != -1 && costForNumFlights[city][flightNum] != -1
                        && (costForNumFlights[flyTo][flightNum + 1] == -1 || costForNumFlights[flyTo][flightNum + 1] > costForNumFlights[city][flightNum] + costToFlyTo[city][flyTo]))
                        costForNumFlights[flyTo][flightNum + 1] = costForNumFlights[city][flightNum] + costToFlyTo[city][flyTo];
                }
            }
        }
        

        vector<long long> bestCost(numCities);
        bestCost[0] = -1;
        
        for (int i = 1; i < numCities; ++i)
        {
            if (bestCost[i - 1] != -1 && costForNumFlights[numCities - 1][i] != -1)
                bestCost[i] = min(bestCost[i - 1], costForNumFlights[numCities - 1][i]);
                
            else
                bestCost[i] = max(bestCost[i - 1], costForNumFlights[numCities - 1][i]);
        }
        
        
        
        cout << "Scenario #" << t << '\n';
        
        int numChecks;
        cin >> numChecks;
        
        while (numChecks--)
        {
            int maxFlights;
            cin >> maxFlights;
            ++maxFlights;
            
            if (maxFlights >= numCities)
                maxFlights = numCities- 1;
                
            if (bestCost[maxFlights] != -1)
                cout << "Total cost of flight(s) is $" << bestCost[maxFlights] << '\n';
            
            else
                cout << "No satisfactory flights\n";
            
        }
    }

}
