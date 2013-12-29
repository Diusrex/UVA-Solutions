#include <cstdio>
#include <string.h>

int main()
{
    
    int T;
    
    scanf("%d", &T);
    
    char best[10][110];
    
    int highest, posInBest, temp;
    
    for (int t = 1; t <= T; ++t)
    {
        
        scanf("%s %d", &best[0], &highest);
        
        posInBest = 1;
        
        for (int i = 0; i < 9; ++i)
        {
            scanf("%s %d", &best[posInBest], &temp);
            
            if (temp > highest)
            {
                strcpy(best[0], best[posInBest]);
                posInBest = 1;
                
                highest = temp;
            }
            
            else if (temp == highest)
               ++posInBest;
        }
        printf("Case #%d:\n", t);
        
        for (int i = 0; i < posInBest; ++i)
            printf("%s\n", best[i]);
    }
}