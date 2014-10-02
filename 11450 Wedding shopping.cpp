#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int UNKNOWN = -1;
const int IMPOSSIBLE = -2;

int C, M;
int moneyLeft[210][25];

int GetBest(int currentGarment, int currentSpent, const vector<vector<int> >& garmentsCosts)
{
    if (currentSpent > M)
        return IMPOSSIBLE;
    if (currentGarment == C)
        return currentSpent;
    
    if (moneyLeft[currentSpent][currentGarment] != UNKNOWN)
        return moneyLeft[currentSpent][currentGarment];
    
    int & best = moneyLeft[currentSpent][currentGarment];
    
    for (int m = 0; m < garmentsCosts[currentGarment].size(); ++m)
    {
        best = max(best, GetBest(currentGarment + 1, currentSpent + garmentsCosts[currentGarment][m], garmentsCosts));
    }
    
    return best;
}

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        cin >> M >> C;
        
        for (int c = 0; c < C; ++c)
        {
            for (int m = 0; m <= M; ++m)
            {
                moneyLeft[m][c] = UNKNOWN;
            }
        }
        vector<vector<int> > garmentsCosts(C);
        
        for (int i = 0; i < C; ++i)
        {
            int k;
            cin >> k;
            garmentsCosts[i].resize(k);
            for (int j = 0; j < k; ++j)
                cin >> garmentsCosts[i][j];
        }
        
        int best = GetBest(0, 0, garmentsCosts);
        
        if (best < 0)
            cout << "no solution\n";
        else
            cout << best << '\n';
    }
}