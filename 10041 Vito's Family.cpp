#include <iostream>
#include <cstdlib>

using namespace std;

int position[505];

int GetCost(int i, const int R)
{
    int total = 0;
    int pos = position[i];
    
    for (int j = 0; j < R; ++j)
        total += abs(position[j] - pos);
    
    return total;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int R;
        cin >> R;
        
        for (int i = 0; i < R; ++i)
            cin >> position[i];
        
        
        
        
        int bestCost = GetCost(0, R);
        
        for (int i = 1; i < R; ++i)
            bestCost = min(bestCost, GetCost(i, R));
        
        cout << bestCost << '\n';
    }
}