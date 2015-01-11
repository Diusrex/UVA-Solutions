#include <cstdio>
#include <vector>

using namespace std;

const int HIGHEST_VALUE = 7490;
int coins[] = {1, 5, 10, 25, 50};

int main()
{
    vector<long long> numWays(HIGHEST_VALUE, 0);
    numWays[0] = 1;
    
    // Solve for all questions
    for (int coin = 0; coin < 5; ++coin)
        for (int from = 0, i = coins[coin]; i < HIGHEST_VALUE; ++from, ++i)
            numWays[i] += numWays[from];
    
    int wanted;
    while (scanf("%d", &wanted) == 1)
    {
        printf("%d\n", numWays[wanted]);
    }
}