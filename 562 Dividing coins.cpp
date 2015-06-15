#include <iostream>
#include <cmath>

using namespace std;

const int UNKNOWN = -1;

const int HIGHEST_POS_FOR_COIN_VAL = 501;

// CoinPos, DiffGoingintoit
int numCoins;
int lowestDiff[105][105 * 501];
int coins[105];

int GetBest(int coin, int diff)
{
    if (coin == numCoins)
        return diff;
    
    int &bestDiff = lowestDiff[coin][diff];
    
    if (bestDiff == UNKNOWN)
    {
        bestDiff = min(GetBest(coin + 1, diff + coins[coin]),
                       GetBest(coin + 1, abs(diff - coins[coin])));
    }
    
    return bestDiff;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> numCoins;
        int highest = HIGHEST_POS_FOR_COIN_VAL * numCoins;
        
        for (int i = 0; i < numCoins; ++i)
        {
            cin >> coins[i];
            for (int j = 0; j < highest; ++j)
            {
                lowestDiff[i][j] = UNKNOWN;
            }
        }
        
        cout << GetBest(0, 0) << '\n';
    }
}