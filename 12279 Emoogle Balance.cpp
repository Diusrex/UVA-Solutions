#include <cstdio>

int main()
{
    int n, temp;
    scanf("%d", &n);
    
    for (int t = 1; n; ++t, scanf("%d", &n))
    {
        int balance(0);
        
        while (n--)
        {
            scanf("%d", &temp);
            if (temp)
                ++balance;
            else
                --balance;
        }
        
        printf("Case %d: %d\n", t, balance);
    }

}