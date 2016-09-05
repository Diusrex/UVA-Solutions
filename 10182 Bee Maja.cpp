#include <iostream>
#include <algorithm>

using namespace std;

// 0,0 -> 1
    // + 1
// 0,1 -> 2
    // + 7
// 0,2 -> 9
    // + 13
// 0,3 -> 22
    // + 19
// 0,4 -> 41

// So each layer is 6 more nodes than previous

int numNodesBy0X[10000];

int xChange[] = {-1, 0, 1, 1, 0, 0, -1};
int yChange[] = {0, -1, -1, 0, 1, 1, 1};

int main()
{
    int sum = 1, current = 1;
    int yMax = 1;
    for (; sum <= 100000; ++yMax, sum += current, current += 6)
    {
        numNodesBy0X[yMax] = sum;
    }
    
    int num;
    while (cin >> num)
    {
        int *position = upper_bound(numNodesBy0X, numNodesBy0X + yMax, num);
        --position;
        
        int xCircleVal = 0;
        int yCircleVal = position - numNodesBy0X - 1;
        const int sideLength = yCircleVal;
        
        
        int distanceLeft = num - *position;
        for (int change = 0; distanceLeft; ++change)
        {
            int move = min(distanceLeft, sideLength);
            if (change == 5)
                move = min(move, 1);
            xCircleVal += xChange[change] * move;
            yCircleVal += yChange[change] * move;
            distanceLeft -= move;
        }
        cout << xCircleVal << ' ' << yCircleVal << '\n';
    }
}