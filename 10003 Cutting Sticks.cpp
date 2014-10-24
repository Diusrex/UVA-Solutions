#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_CUT_SIZE = 55;
int bestCost[MAX_CUT_SIZE][MAX_CUT_SIZE];

int cut(int left, int right, const vector<int> & cuts)
{
    int & current = bestCost[left][right];
    
    if (current == -1)
    {
        current = 0;
        for (int i = left + 1; i < right; ++i)
        {
            if (current == 0)
                current = cut(left, i, cuts) + cut(i, right, cuts) + cuts[right] - cuts[left];
            else
                current = min(current, cut(left, i, cuts) + cut(i, right, cuts) + cuts[right] - cuts[left]);
        }
    }
    return current;
}

int main()
{
    int L;
    while (cin >> L, L)
    {
        int numCuts;
        cin >> numCuts;
        
        for (int i = 0; i < MAX_CUT_SIZE; ++i)
        {
            for (int j = 0; j < MAX_CUT_SIZE; ++j)
            {
                bestCost[i][j] = -1;
            }
        }
        
        vector<int> cuts(numCuts + 2);
        cuts[0] = 0;
        for (int i = 1; i <= numCuts; ++i)
        {
            cin >> cuts[i];
        }
        cuts[numCuts + 1] = L;
        
        cout << "The minimum cutting is " << cut(0, cuts.size() - 1, cuts) << ".\n";
    }
}