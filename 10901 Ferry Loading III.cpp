#include <iostream>
#include <queue>

using namespace std;

int charToSide[128];

int main()
{
    charToSide['l'] = 0;
    charToSide['r'] = 1;
    
    int T;
    cin >> T;
    
    string sep = "", sideStr;
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        int maxLoad, crossTime, totalNumCars;
        
        cin >> maxLoad >> crossTime >> totalNumCars;
        vector<long long> leaveTime(totalNumCars);
        
        queue<int> lines[2];
        
        long long currentTime = 0, lastCarTime = -1;
        int currentSide = 0, numCarsLoaded = 0;
        
        cin >> lastCarTime >> sideStr;
        
        while (numCarsLoaded < totalNumCars)
        {
            // Want to:
                // Load cars until their time is > the current time
                // If there are no cars waiting, then change time to be that cars arrival time
            
            // If the time was > currentTime, then will be going to other side immediately
            if (lastCarTime <= currentTime)
            {
                // The most recent car loaded would NOT be added immediately
                lines[charToSide[sideStr[0]]].push(numCarsLoaded);
                ++numCarsLoaded;
                
                // What this should do is load in until it has
                while (numCarsLoaded < totalNumCars && cin >> lastCarTime >> sideStr && lastCarTime <= currentTime)
                {
                    lines[charToSide[sideStr[0]]].push(numCarsLoaded);
                    ++numCarsLoaded;
                }
            } 
            
            else if (lines[0].empty() && lines[1].empty()) // Need to go to the future time, cause no cars remaining
            {
                currentTime = lastCarTime;
                lines[charToSide[sideStr[0]]].push(numCarsLoaded);
                ++numCarsLoaded;
                
                while (numCarsLoaded < totalNumCars && cin >> lastCarTime >> sideStr && lastCarTime <= currentTime)
                {
                    lines[charToSide[sideStr[0]]].push(numCarsLoaded);
                    ++numCarsLoaded;
                }
            }
            
            // Handle transferring cars over
            for (int i = 0; i < maxLoad && !lines[currentSide].empty(); ++i)
            {
                int carNum = lines[currentSide].front(); lines[currentSide].pop();
                leaveTime[carNum] = currentTime + crossTime;
            }
            
            currentSide = 1 - currentSide;
            currentTime += crossTime;
        }
        
        // While there are cars left, cross back and forth
        while (!lines[0].empty() || !lines[1].empty())
        {
            for (int i = 0; i < maxLoad && !lines[currentSide].empty(); ++i)
            {
                int carNum = lines[currentSide].front(); lines[currentSide].pop();
                leaveTime[carNum] = currentTime + crossTime;
            }
            
            currentSide = 1 - currentSide;
            currentTime += crossTime;
        }
        
        for (int i = 0; i < totalNumCars; ++i)
        {
            cout << leaveTime[i] << '\n';
        }
    }
}