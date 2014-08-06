#include <cstdio>
#include <algorithm>

#define dayRate {0.1, 0.25, 0.53, 0.87, 1.44}
#define eveningRate {0.06, 0.15, 0.33, 0.47, 0.8}
#define nightRate {0.02, 0.05, 0.13, 0.17, 0.3}

int GetTimeInMin()
{
    int hr, min;
    scanf("%d%d", &hr, &min);
    return hr * 60 + min;
}

const int NUM_TIME_PERIODS = 4;

double rates[NUM_TIME_PERIODS][5] = {nightRate, dayRate, eveningRate, nightRate};
int endTimes[NUM_TIME_PERIODS] = {480, 1080, 1320, 1440};
int timeInPeriod[NUM_TIME_PERIODS];

void DetermineTimeInPeriods(const int startTime, const int endTime)
{
    int currentPeriod = 0;
    
    while (startTime >= endTimes[currentPeriod])
        ++currentPeriod;
    
    int currentTime = startTime;
    int newTime;
    
    while (currentTime != endTime)
    {
        if (currentPeriod == NUM_TIME_PERIODS)
        {
            currentTime = 0;
            currentPeriod = 0;
        }
        
        
        if (endTime >= currentTime)
            newTime = std::min(endTime, endTimes[currentPeriod]);
        else
            newTime = endTimes[currentPeriod];
            
        timeInPeriod[currentPeriod] += newTime - currentTime;
        
        currentTime = newTime;
        ++currentPeriod;
    }
}

double SumCost(int ratePos)
{
    double cost = 0;
    
    for (int i = 0; i < NUM_TIME_PERIODS; ++i)
        cost += timeInPeriod[i] * rates[i][ratePos];

    return cost;
}

// C 937-7295 11 17 08 37
// 440 240 600

int main()
{
    
    char numberCalled[10];
    char chargeStep;
    int startTime, callEndTime;
    
    while (scanf(" %c", &chargeStep), chargeStep != '#')
    {
        scanf("%s", numberCalled);
        startTime = GetTimeInMin();
        callEndTime = GetTimeInMin();
        timeInPeriod[0] = timeInPeriod[1] = timeInPeriod[2] = timeInPeriod[3] = 0;
        
        if (startTime != callEndTime)
            DetermineTimeInPeriods(startTime, callEndTime);
        else
        {
            // The times are their max (faster for preset)
            timeInPeriod[0] = 600;
            timeInPeriod[1] = 600;
            timeInPeriod[2] = 240;
        }
        printf("%10s%6d%6d%6d%3c%8.2f\n", numberCalled, timeInPeriod[1], timeInPeriod[2], timeInPeriod[3] + timeInPeriod[0], chargeStep, SumCost(chargeStep - 'A'));
    }
}