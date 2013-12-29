#include <cstdio>

int main()
{
    int T, N, current, max;
    
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        max = 1;
        
        scanf("%d", &   N);
        
        while (N--)
        {
            scanf("%d", &current);
            
            if (max < current)
                max = current;
        
        }
        
        printf("Case %d: %d\n", t, max);
    }
}