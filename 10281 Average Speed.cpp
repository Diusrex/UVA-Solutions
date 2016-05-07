#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << setprecision(2) << fixed << setfill('0');
    double distance = 0;
    
    int previousTime = 0, currentSpeedInKmpH = 0;
    
    int hour, min, second;
    char junk1, junk2;
    
    while (cin >> hour >> junk1 >> min >> junk2 >> second)
    {
        int currentTime = hour * 3600 + min * 60 + second;
        int timeTravelled = currentTime - previousTime;
        
        double currentDistanceTravelled = currentSpeedInKmpH * (timeTravelled / 3600.0);
        
        if (cin.peek() == ' ')
        {
            // Update distance
            distance += currentDistanceTravelled;
            
            previousTime = currentTime;
            cin >> currentSpeedInKmpH;
            
        }
        else
        {
            // Printout
            cout << setw(2) << hour << ':' <<
                    setw(2) << min << ':' <<
                    setw(2) << second << ' ' 
                    << (distance + currentDistanceTravelled) << " km\n";
            
        }
    }
    
}