#include <cstdio>
#include <cmath>

int main()
{
    int T = 1, t, total, current, temp;
    
    while (scanf("%d", &total), total)
    {
        t = 0;
        current = 0;
        
        printf("Output for data set %d, %d bytes:\n", T++, total);
        
        while (total > 0)
        {
            scanf("%d", &temp);
            
            ++t;
            
            if (temp > 0)
            {
                current += temp;
                total -= temp;
            }
            
            if (t % 5 == 0 && t != 0)
            {
                if (current > 0)
                    printf("   Time remaining: %d seconds\n", (int) ceil(total * 5.0 / current));
                else
                    printf("   Time remaining: stalled\n");
                current = 0;
            }
            
            
        }
        printf("Total time: %d seconds\n\n", t);
    }
}