#include <iostream>
#include <algorithm>

using namespace std;

const int START = 1;

int bestHeight[10005];

int main()
{
    int largestEnd = 0;
    int start, height, end;
    
    while (cin >> start >> height >> end)
    {
        if (largestEnd < end)
            largestEnd = end;
        
        for (int i = start; i < end; ++i)
            bestHeight[i] = max(bestHeight[i], height);
    }
    
    int best = bestHeight[1];
    cout << "1 " << best;
    
    for (int i = 2; i < largestEnd; ++i)
    {
        if (best != bestHeight[i])
        {
            cout << ' ' << i << ' ' << bestHeight[i];
            best = bestHeight[i];
        }
    }
    cout << ' ' << largestEnd << " 0\n";
}

