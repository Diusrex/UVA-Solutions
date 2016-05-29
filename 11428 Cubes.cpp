#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Found that this was the largest number used in the range
const int MaxSize = 60;
ull cubes[MaxSize];

int main()
{
    for (ull i = 1; i < MaxSize; ++i)
        cubes[i] = i * i * i;
    
    ull goal;
    while (cin >> goal, goal)
    {
        int x, y;
        ull * minCube = lower_bound(cubes + 1, cubes + MaxSize, goal);
        bool isFound = false;

        for (x = minCube - cubes; x < MaxSize; ++x)
        {
            ull target = cubes[x] - goal;
            if (target > cubes[MaxSize - 1])
                break;
            
            ull *found = lower_bound(cubes + 1, cubes + MaxSize, target);
            if (*found == target)
            {
                y = found - cubes;
                isFound = true;
                break;
            }
        }
        
        if (isFound)
        {
            cout << x << ' ' << y << '\n';
        }
        else
            cout << "No solution\n";
    }
}