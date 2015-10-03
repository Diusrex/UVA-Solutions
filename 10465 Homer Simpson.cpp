#include <iostream>



using namespace std;

// If == -1, not known
int numBurgersAtT[10005];


// Simple DP, on a single dimension array
// burgers[t] = max(burgers[t - m] + 1, burger[t - n] + 1)
// Then, to check if drink beer, check if highest is at burgers[T]
//      If not, then the time wasted is T - argmaxt


int main()
{
    int m, n, t;
    while (cin >> m >> n >> t)
    {
        int largestIndex = 0;
        numBurgersAtT[0] = 0;
        
        for (int i = 1; i <= t; ++i)
        {
            numBurgersAtT[i] = -1;
            if (i >= m && numBurgersAtT[i - m] >= 0)
                numBurgersAtT[i] = numBurgersAtT[i - m] + 1;
            if (i >= n && numBurgersAtT[i - n] >= 0)
                numBurgersAtT[i] = max(numBurgersAtT[i - n] + 1, numBurgersAtT[i]);
        }
        
        if (numBurgersAtT[t] >= 0)
            cout << numBurgersAtT[t] << '\n';
        else
        {
            int cost = 1;
            while (numBurgersAtT[t - cost] == -1)
                ++cost;
            
            cout << numBurgersAtT[t - cost] << ' ' << cost << '\n';
        }
    }
}