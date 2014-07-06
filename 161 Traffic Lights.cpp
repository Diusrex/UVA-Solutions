#include <cstdio>
#include <vector>

using namespace std;

const int numSecInMin = 60;
const int numSecInHr = 60 * numSecInMin;
const int fiveHours = 5 * numSecInHr;


bool AllGreen(const vector<int>& times, const vector<int>& doubleTimes, const int &currentTime)
{
    for (int i = 0; i < times.size(); ++i)
    {
        if (! (currentTime % doubleTimes[i] < times[i] - 5))
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int firstLight;
    
    while (scanf("%d", &firstLight), firstLight)
    {
        vector<int> times(1, firstLight);
        vector<int> doubleTimes(1, firstLight * 2);
        
        int num;
        int min = firstLight;
        
        while (scanf("%d", &num), num)
        {
            times.push_back(num);
            doubleTimes.push_back(num * 2);
            if (num < min)
                min = num;
        }
        
        int currentTime = min * 2;
        
        bool allGreen;
        
        while (!(allGreen = AllGreen(times, doubleTimes, currentTime)) && currentTime <= fiveHours)
        {
            ++currentTime;
        }
        
        if (allGreen)
        {
            int hr = currentTime / numSecInHr;
            
            printf("0%d:%02d:%02d\n", currentTime / numSecInHr, (currentTime - hr * numSecInHr) / numSecInMin, currentTime % numSecInMin);
        }
        
        else
        {
            printf("Signals fail to synchronise in 5 hours\n");
        }
    }
}