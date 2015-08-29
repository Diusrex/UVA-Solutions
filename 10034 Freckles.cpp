#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// Read in
// Create Distance list, containing all distances
// Sort Distance list, then iterate through it

double frecklesX[105];
double frecklesY[105];

double GetDistance(int freckle1, int freckle2)
{
    double xDiff = frecklesX[freckle1] - frecklesX[freckle2];
    double yDiff = frecklesY[freckle1] - frecklesY[freckle2];
    
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

struct Distance
{
    double distance;
    int freckle1, freckle2;
    
    bool operator<(const Distance & other) const
    {
        return distance < other.distance;
    }
};

Distance allDistances[105 * 105];
bool connected[105];

double totalCost;

void Connect(const Distance & dist)
{
    connected[dist.freckle1] = connected[dist.freckle2] = true;
    totalCost += dist.distance;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        if (t)
            cout << '\n';
        
        int N;
        cin >> N;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> frecklesX[i] >> frecklesY[i];
            connected[i] = false;
        }
        
        int numDistances = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                double distance = GetDistance(i, j);
                allDistances[numDistances].distance = distance;
                allDistances[numDistances].freckle1 = i;
                allDistances[numDistances].freckle2 = j;
                ++numDistances;
            }
        }
        
        sort(allDistances, allDistances + numDistances);
        
        totalCost = 0;
        
        int numConnected = 2;
        Connect(allDistances[0]);
        
        for (; numConnected < N; ++numConnected)
        {
            for (int i = 1; ; ++i)
            {
                if (connected[allDistances[i].freckle1] ^ connected[allDistances[i].freckle2]) // Only 1 has been connected
                {
                    Connect(allDistances[i]);
                    break;
                }
            }
        }
        
        cout << setprecision(2) << std::fixed << totalCost << '\n';
    }
}