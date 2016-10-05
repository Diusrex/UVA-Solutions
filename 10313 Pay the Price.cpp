#include <iostream>
#include <sstream>

using namespace std;

const int MaxAmount = 301;
unsigned long long usingAnyAmountOfCoins[MaxAmount];
// [Cost][NumCoins]
unsigned long long usingSpecificAmount[MaxAmount][MaxAmount];

int main()
{
    usingAnyAmountOfCoins[0] = 1;
    for (int coin = 1; coin < MaxAmount; ++coin)
    {
        for (int amount = coin; amount < MaxAmount; ++amount)
        {
            usingAnyAmountOfCoins[amount] += usingAnyAmountOfCoins[amount - coin];
        }
    }
    
    usingSpecificAmount[0][0] = 1;
    for (int coin = 1; coin < MaxAmount; ++coin)
    {
        for (int amount = coin; amount < MaxAmount; ++amount)
        {
            for (int numCoins = 1; numCoins < MaxAmount; ++numCoins)
            {
                usingSpecificAmount[amount][numCoins] += usingSpecificAmount[amount - coin][numCoins - 1];
            }
        }
    }
    
    int N, L1, L2;
    
    while (cin >> N)
    {
        string str;
        getline(cin, str);
        stringstream ss(str);
        
        unsigned long long count = usingAnyAmountOfCoins[N];
        if (ss >> L1)
        {
            count = 0;
            if (ss >> L2)
            {
                for (int i = L1; i <= L2 && i < MaxAmount; ++i)
                    count += usingSpecificAmount[N][i];
            }
            else
            {
                for (int i = 0; i <= L1 && i < MaxAmount; ++i)
                    count += usingSpecificAmount[N][i];
            }
        }
        cout << count << '\n';
    }
}