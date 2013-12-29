#include <cstdio>

int main()
{
    int T, N, num, mileCost, juiceCost;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &N);
        mileCost = juiceCost = 0;
        while (N--)
        {
            scanf("%d", &num);
            mileCost += (num / 30) * 10 + 10;
            juiceCost += (num / 60) * 15 + 15;
        }
        printf("Case %d: ", t);
        
        if (mileCost < juiceCost)
            printf("Mile %d\n", mileCost);
        else if (mileCost == juiceCost)
            printf("Mile ");
        
        if (juiceCost <= mileCost)
            printf("Juice %d\n", juiceCost);
    }
}