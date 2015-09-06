#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int INVALID = 100000;

int distanceFrom[105][105];

int main()
{
    int a, b;
    int T = 1;
    
    while (cin >> a >> b, a)
    {
        
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 101; ++j)
            {
                distanceFrom[i][j] = INVALID; // Large enough number that it is larger than actual max
            }
            
        distanceFrom[a][b] = 1;
        
        while (cin >> a >> b, a)
            distanceFrom[a][b] = 1;
        
        for (int k = 1; k < 101; ++k)
            for (int i = 1; i < 101; ++i)
                for (int j = 1; j < 101; ++j)
                    distanceFrom[i][j] = min(distanceFrom[i][j], distanceFrom[i][k] + distanceFrom[k][j]);
        
        int sum = 0, numConnected = 0;
        for (int i = 1; i < 101; ++i)
            for (int j = 1; j < 101; ++j)
            {
                if (i != j && distanceFrom[i][j] != INVALID)
                {
                    sum += distanceFrom[i][j];
                    ++numConnected;
                }
            }
            
        cout << "Case " << T++ << ": average length between pages = " << setprecision(3) << fixed << (1.0 * sum / numConnected) << " clicks\n";
    }
}