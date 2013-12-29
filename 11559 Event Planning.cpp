#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int N, B, numH, numWeeks, currentPrice, currentNumBeds, bestPrice;
    
    
    while (scanf("%d", &N))
    {
        scanf("%d %d %d", &B, &numH, &numWeeks);
        
        bestPrice = B + 1;
        
        while (numH--)
        {
            scanf("%d", &currentPrice);
            
            for (int i = 0; i < numWeeks; ++i)
            {
                scanf("%d", &currentNumBeds);
                if (currentNumBeds >= N)
                {
                    //printf("New is: %d\n", N * currentPrice);
                    if (N * currentPrice < bestPrice)
                        bestPrice = N * currentPrice;
                }
            }
        }
        
        
        if (bestPrice <= B)
            printf("%d\n", bestPrice);
        else
            printf("stay home\n");
    }

}