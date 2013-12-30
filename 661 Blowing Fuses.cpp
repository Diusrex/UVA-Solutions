#include <cstdio>

int main()
{
    int n, m, c, t, currentCost, eachCost[21], currentCheck, maxCost, onesOn;
    
    t = 1;
    
    while (scanf("%d %d %d", &n, &m, &c), n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &eachCost[i]);
        }   
        
        currentCost = maxCost = onesOn = 0;
        
        while (m--)
        {
            scanf("%d", &currentCheck);
            
            if (maxCost <= c)
            {
                if (onesOn & (1 << currentCheck))
                    currentCost -= eachCost[currentCheck - 1];
                
                else
                {
                    currentCost += eachCost[currentCheck - 1];
                    if (currentCost > maxCost)
                        maxCost = currentCost;
                }
                    
                onesOn ^= (1 << currentCheck);
            }
        }
        
        printf("Sequence %d\n", t);
        
        if (maxCost > c)
            printf("Fuse was blown.\n\n");
        else
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", maxCost);
        
        ++t;
    }
}