#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int n, i, k;
        cin >> n >> i >> k;
        int numTimesInactive = 0, numIgnored = 0;
        int currentTime, activeTime = 0;
        
        while (n--)
        {
            cin >> currentTime;
            if (currentTime >= activeTime + i)
            {
                ++numTimesInactive;
                activeTime = currentTime + k;
            }
            else if (currentTime < activeTime)
                ++numIgnored;
            else
                activeTime = currentTime;
                
        }
        
        cout << "Case " << t << ": " << numTimesInactive << ' ' << numIgnored << '\n';
    }
}