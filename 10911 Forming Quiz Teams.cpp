#include <iostream>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cmath>

using namespace std;

void matchWithOthers(bitset<16> matchedUp, int currentCheck, const int& numPeople, const vector<vector<double> >& dist, double currentCost, double& minCost)
{    
    // Is guarentted to have been matched already
    if (currentCheck + 1 == numPeople)
    {        
        if (currentCost < minCost || minCost == -1)
            minCost = currentCost;
        
        return;
    }
    
    if (matchedUp[currentCheck])
    {
        matchWithOthers(matchedUp, currentCheck + 1, numPeople, dist, currentCost, minCost);
    }
    
    else
    {
        matchedUp[currentCheck] = true;
        
        for (int i = currentCheck + 1; i < numPeople; ++i)
        {
            // If it isnt, there is not point in trying
            if (!matchedUp[i] && (currentCost + dist[currentCheck][i] < minCost || minCost == -1))
            {
                unsigned long long origionalCost = minCost;
                matchedUp[i] = true;
                //cout << "Comparing: " << currentCheck << " and " << i << ':' << dist[currentCheck][i] << '\n';
                matchWithOthers(matchedUp, currentCheck + 1, numPeople, dist, currentCost + dist[currentCheck][i], minCost);
                matchedUp[i] = false;
            }
        }
    }
}


int main()
{
    cout << fixed << setprecision(2);
    
    int numGroups;
    cin >> numGroups;
    
    for (int t = 1; numGroups; ++t, cin >> numGroups)
    {
        
        vector<pair<int, int> > eachPos(numGroups * 2);
        
        string name;
        
        pair<int, int> temp;
        
        for (int i = 0; i < numGroups * 2; ++i)
        {
            cin >> name >>  temp.first >> temp.second;

            eachPos[i] = temp;
        }
        
        vector<vector<double> > dist(numGroups * 2, vector<double>(numGroups * 2));
        
        for (int x = 0; x < numGroups * 2; ++x)
        {
            for (int y = 0; y < numGroups * 2; ++y)
            {
                dist[x][y] = (eachPos[x].first - eachPos[y].first) * (eachPos[x].first - eachPos[y].first) + (eachPos[x].second - eachPos[y].second) * (eachPos[x].second - eachPos[y].second);
                
                dist[x][y] = sqrt(dist[x][y]);
            }
        }
        
        bitset<16> matchedUp;
        // Sets it the max possible
        double cost = -1;
        
        matchWithOthers(matchedUp, 0, numGroups * 2, dist, 0, cost);
        
        cout << "Case " << t << ": " << cost << '\n';
    }

}