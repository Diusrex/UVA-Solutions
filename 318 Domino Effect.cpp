#include <iostream>
#include <iomanip>
#include <utility>

using namespace std;

const int INVALID = -1;
const int INF = 99999999;
int timeConnected[505][505];
int timeFell[505];
bool evaluated[505];
int N;

// latest2 is for if it falls between two different ones
int latestKey1, latestKey2;
double latestTime;

void Calculate()
{
    timeFell[0] = 0;
    
    // Only need to expand from N - 1 nodes
    int temp = N - 1;
    
    while (temp--)
    {
        int bestNode, bestTime = INF;
        for (int i = 0; i < N; ++i)
            if (timeFell[i] < bestTime && !evaluated[i])
            {
                bestNode = i;
                bestTime = timeFell[i];
            }
        
        evaluated[bestNode] = true;
        
        
        for (int i = 0; i < N; ++i)
            if (timeConnected[bestNode][i] != INVALID)
                timeFell[i] = min(timeFell[i], bestTime + timeConnected[bestNode][i]);
    }
    
    latestTime = -1;
    latestKey2 = INVALID;
    for (int i = 0; i < N; ++i)
        if (timeFell[i] > latestTime)
        {
            latestTime = timeFell[i];
            latestKey1 = i;
        }
    
    // Find any ones where highest time is instead the time between them
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            double timeFractionFromiToj = (timeConnected[i][j] - timeFell[i] + timeFell[j]) / 2.0;
            double meetTime = timeFractionFromiToj + timeFell[i];
            // Will meet somewhere in the middle
            if (timeFractionFromiToj > 0 && timeFractionFromiToj < timeConnected[i][j]
                && meetTime > latestTime)
            {
                latestTime = meetTime;
                latestKey1 = i;
                latestKey2 = j;
            }
        }
    }
}

int main()
{
    cout << fixed << setprecision(1);
    int M, T = 1;
    while (cin >> N >> M, N)
    {
        for (int i = 0; i < N; ++i)
        {
            timeFell[i] = INF;
            evaluated[i] = false;
            
            for (int j = 0; j < N; ++j)
                timeConnected[i][j] = INVALID;
        }
            
        while (M--)
        {
            int a, b, s;
            cin >> a >> b >> s;
            --a; --b;
            
            timeConnected[a][b] = timeConnected[b][a] = s;
        }
        
        Calculate();
        ++latestKey1; ++latestKey2;
        cout << "System #" << T++ << "\n";
        if (!latestKey2)
            cout << "The last domino falls after " << latestTime << " seconds, at key domino " << latestKey1 << ".\n\n";

        else
            cout << "The last domino falls after " << latestTime << " seconds, between key dominoes " << latestKey1 << " and " << latestKey2 << ".\n\n";
    }
}