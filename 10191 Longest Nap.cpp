#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

const int TOTAL_MINUTES = 8 * 60;

int main()
{
    std::string junk;
    
    int N;
    
    int T = 1;
    
    vector<bool> timeAvailable(TOTAL_MINUTES + 2);
    timeAvailable[TOTAL_MINUTES + 1] = false;
    
    while (cin >> N)
    {
        for (int i = 0; i <= TOTAL_MINUTES; ++i)
            timeAvailable[i] = true;

        
        
        while (N--)
        {
            int startHr, startMin, endHr, endMin;
            int startTime, endTime;
            char startSeparator, endSeparator;
        
            cin >> startHr >> startSeparator >> startMin >> endHr >> endSeparator >> endMin;
            getline(cin, junk);

            startTime = (startHr - 10) * 60 + startMin;
            endTime = (endHr - 10) * 60 + endMin;
            
            for (int i = startTime; i < endTime; ++i)
                timeAvailable[i] = false;
        }
        
        int bestStartTime, bestLength = 0;
        
        for (int i = 0; i <= TOTAL_MINUTES; ++i)
        {
            if (timeAvailable[i])
            {
                int j = i + 1;
                
                while (timeAvailable[j])
                    ++j;
                
                if (j == TOTAL_MINUTES + 1)
                    --j;
                    
                if (j - i > bestLength)
                {
                    bestStartTime = i;
                    bestLength = j - i;
                }
                
                i = j;
            }
        }
        
        if (bestLength >= 60)
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", 
                T++, bestStartTime / 60 + 10, bestStartTime % 60, bestLength / 60, bestLength % 60);
        else
            printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", 
                T++, bestStartTime / 60 + 10, bestStartTime % 60, bestLength);
    }

}