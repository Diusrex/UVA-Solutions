#include <iostream>
#include <sstream>

using namespace std;

const int NumIntersections = 501;
const int NumFireStations = 101;
const int NoPath = 1e9;

int F, N;

// Will start off with NoPath
int distances[NumIntersections][NumIntersections];

int distanceToFire[NumIntersections];

int fireStationIntersections[NumFireStations];

int main()
{
    int T;
    cin >> T;
    
    string sep = "";
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        cin >> F >> N;
        for (int i = 0; i < N; ++i)
        {
            distanceToFire[i] = NoPath;
            for (int j = 0; j < N; ++j)
            {
                distances[i][j] = NoPath;
            }
            distances[i][i] = 0;
        }
        
        for (int i = 0; i < F; ++i)
        {
            int station;
            cin >> station;
            --station;
            // intersection already identified as station
            if (distanceToFire[station] == 0)
            {
                --i;
                --F;
            }
            else
            {
                distanceToFire[station] = 0;
                fireStationIntersections[i] = station;
            }
        }
        
        cin.ignore();
        
        string line;
        
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);
            int s, e, dist;
            ss >> s >> e >> dist;
            --s; --e;
            
            distances[s][e] = distances[e][s] = min(distances[s][e], dist);
        }
        
        // Calculate all distances first
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
        
        // Calcuate distance to closest fire station
        for (int i = 0; i < N; ++i)
        {
            // Not at a fire station already
            if (distanceToFire[i])
            {
                for (int j = 0; j < F; ++j)
                {
                    distanceToFire[i] = min(distanceToFire[i], distances[i][fireStationIntersections[j]]);
                }
            }
        }
        
        // Calculate which is the best to place a new one
        int bestMaxDist = NoPath;
        int bestIntersection = 0; // In case all have fire station, doesn't matter
        for (int i = 0; i < N; ++i)
        {
            // Not at a fire station already
            if (distanceToFire[i])
            {
                // Will try picking i as the new fire station
                int maxDist = 0;
                for (int j = 0; j < N; ++j)
                {
                    maxDist = max(maxDist, min(distanceToFire[j], distances[j][i]));
                }
                
                if (maxDist < bestMaxDist)
                {
                    bestMaxDist = maxDist;
                    bestIntersection = i;
                }
            }
        }
        
        
        cout << (bestIntersection + 1) << '\n';
    }
}