#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const int maxSeconds = 60 * 60;

bool AllGreen(int time, const vector<int>& timings)
{
    for (int i = 0; i < timings.size(); ++i)
    {
        if ((time % (timings[i] * 2)) >= (timings[i] - 5))
            return false;
    }
    
    return true;
}

int main()
{
    string line;
    
    int T = 1;
    while (getline(cin, line))
    {
        stringstream ss(line);
        
        vector<int> timings;
        int lowestTimer = 90;
        
        int time;
        while (ss >> time)
        {
            timings.push_back(time);
            if (time < lowestTimer)
                lowestTimer = time;
        }
        
        int currentTime = lowestTimer * 2;
        
        while (!AllGreen(currentTime, timings) && currentTime <= maxSeconds)
            ++currentTime;
        
        if (currentTime == maxSeconds + 1)
        {
            cout << "Set " << T << " is unable to synch after one hour.\n";
        }
        
        else
        {
            cout << "Set " << T << " synchs again at " << currentTime / 60 << " minute(s) and " << currentTime % 60 << " second(s) after all turning green.\n";
        }
        
        ++T;
    }
}