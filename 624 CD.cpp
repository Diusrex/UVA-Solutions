#include <iostream>
#include <vector>

using namespace std;

#define BASE_TIME Time

int Time, NumTracks;
vector<int> lengthOfTrack;

// Is [track][Time]
vector<vector<int > > minutesWasted;
vector<vector<int > > nextOne;

const int UNKNOWN = -1;

// Means trying the track with timeLeft
int TimeWasted(int track, int timeLeft)
{
    int &wasted = minutesWasted[track][timeLeft];
    if (wasted == UNKNOWN)
    {
        int trackLen = lengthOfTrack[track];
        int &goesTo = nextOne[track][timeLeft];
        
        if (trackLen > timeLeft)
        {
            wasted = timeLeft;
        }
        else
        {
            timeLeft -= trackLen;
            wasted = timeLeft;
            
            goesTo = -1;
            
            for (int i = track + 1; i < NumTracks; ++i)
            {
                int newTime = TimeWasted(i, timeLeft);
                if (newTime < wasted)
                {
                    wasted = newTime;
                    goesTo = i;
                }
            }
        }
    }
    
    return wasted;
}

void GoToNext(int &current, int &currentWasted, int minWasted)
{
    int len = lengthOfTrack[current];
    current = nextOne[current][currentWasted];
    currentWasted -= len;
}

int main()
{
    while (cin >> Time >> NumTracks)
    {
        lengthOfTrack.resize(NumTracks);
        for (int i = 0; i < NumTracks; ++i)
            cin >> lengthOfTrack[i];
        
        minutesWasted.assign(NumTracks, vector<int>(Time + 1, UNKNOWN));
        nextOne.assign(NumTracks, vector<int>(Time + 1, UNKNOWN));
        
        int minWasted = TimeWasted(0, BASE_TIME);
        int bestStart = 0;
        
        for (int i = 1; i < NumTracks; ++i)
        {
            int wasted = TimeWasted(i, BASE_TIME);
            if (wasted < minWasted)
            {
                minWasted = wasted;
                bestStart = i;
            }
        }
        
        int current = bestStart;
        int currentWasted = BASE_TIME;
        
        while (current != -1)
        {
            cout << lengthOfTrack[current] << ' ';
            GoToNext(current, currentWasted, minWasted);
        }
        
        cout << "sum:" << Time - minWasted << '\n';
    }
}