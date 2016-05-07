#include <iostream>

using namespace std;

int numStations;

const int MaxCost = 10005 * 2005;
const int MaxFuel = 200;

// When arriving at station with that much gas
int distanceTravelled[105];
int gasPrice[105];
int bestCost[105][205];

int GetBestCost(int station, int gasLeft)
{
    if (gasLeft < 0)
        return MaxCost + 10;
    
    if (station == numStations)
    {
        if (gasLeft < 100)
            return MaxCost + 10;
        return 0;
    }
    
    
    int &best = bestCost[station][gasLeft];
    
    if (best == -1)
    {
        best = MaxCost + 10;
        
        int gasToMakeItToNext = distanceTravelled[station + 1] - distanceTravelled[station];
        
        // Try each increment of gas to take from here
        for (int gasUsed = max(gasLeft, gasToMakeItToNext); gasUsed <= MaxFuel; ++gasUsed)
        {
            best = min(best, GetBestCost(station + 1, gasUsed - gasToMakeItToNext) + (gasUsed - gasLeft) * gasPrice[station]);
        }
    }
    
    return best;
}

int main()
{
    int T;
    cin >> T;
    string sep = "";
    string ignore;
    while (T--)
    {
        cout << sep;
        sep = "\n";
    
        int initialDist;
        cin >> initialDist;
        
        numStations = 0;
        // Ignore the newline, then check if it has a number on the line
        while (getline(cin, ignore), cin.peek() >= '0' && cin.peek() <= '9')
        {
            cin >> distanceTravelled[numStations] >> gasPrice[numStations];
            if (distanceTravelled[numStations] <= initialDist)
                ++numStations;
        }
        
        distanceTravelled[numStations] = initialDist;
        
        // Now, reset the data
        for (int station = 0; station <= numStations; ++station)
        {
            for (int gas = 0; gas <= 200; ++gas)
                bestCost[station][gas] = -1;
        }
        
        // Start with 100 gas, but then need to travel to first gas station
        int cost = GetBestCost(0, 100 - distanceTravelled[0]);
        
        if (cost > MaxCost)
            cout << "Impossible\n";
        else
            cout << cost << '\n';
    }
}