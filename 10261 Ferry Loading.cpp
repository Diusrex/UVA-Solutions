#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MaxFerryLength = 101 * 100;
// Each car is at smallest 1m
const int MaxCarCanLoad = 202;

vector<int> cars;
// [car][lhsLength] - rhs length will be ~carSum[car] - lhsLength
bool loadedPreviousToLHS[MaxCarCanLoad][MaxFerryLength];

// Sum space saving trick - alternate between two arrays.
bool canReachLength[2][MaxFerryLength];

int main()
{
    int T;
    cin >> T;
    string sep = "";
    while (T--)
    {
        cout << sep;
        sep = "\n";
        cars.clear();
        int canReachIndex = 0;
        int ferryLength;
        cin >> ferryLength;
        ferryLength *= 100;
        
        int lengthSum = 0;
        int numCar = 0;
        int previousFrom;
        int car;
        bool possible = true;
        
        canReachLength[canReachIndex][0] = true;
        for (int i = 1; i <= ferryLength; ++i)
            canReachLength[canReachIndex][i] = false;
        while (cin >> car, car)
        {
            if (possible)
            {
                cars.push_back(car);
                const int nextCanReach = 1 - canReachIndex;
                for (int i = 0; i <= ferryLength; ++i)
                    canReachLength[nextCanReach][i] = false;
                
                lengthSum += car;
                bool reachedOne = false;
                for (int i = 0; i <= ferryLength; ++i)
                    if (canReachLength[canReachIndex][i])
                    {
                        if (i + car <= ferryLength)
                        {
                            reachedOne = true;
                            previousFrom = i + car;
                            loadedPreviousToLHS[numCar + 1][i + car] = true;
                            canReachLength[nextCanReach][i + car] = true;
                        }
                        if (lengthSum - i <= ferryLength && numCar != 0)
                        {
                            reachedOne = true;
                            previousFrom = i;
                            loadedPreviousToLHS[numCar + 1][i] = false;
                            canReachLength[nextCanReach][i] = true;
                        }
                    }
                possible = reachedOne;
                if (possible)
                    ++numCar;
                canReachIndex = nextCanReach;
                
            }
        }
        
        // Reconstruct
        cout << numCar << '\n';
        stack<string> out;
        
        int lhsSize = 0, rhsSize = 0;
        for (; numCar > 0; --numCar)
        {
            if (loadedPreviousToLHS[numCar][previousFrom])
            {
                out.push("port");
                previousFrom -= cars[numCar - 1];
                lhsSize += cars[numCar - 1];
            }
            else
            {
                out.push("starboard");
                rhsSize += cars[numCar - 1];
            }
        }
        
        while (!out.empty())
        {
            cout << out.top() << '\n';
            out.pop();
        }
    }
}