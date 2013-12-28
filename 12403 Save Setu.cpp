#include <cstdio>

int main()
{
    int K, change, total(0);
    
    char s[100];
    scanf("%d", &K);
    
    while (K--)
    {
        scanf("%s", s);
        
        if (s[0] == 'd')
        {
            scanf("%d", &change);
            total += change;
        }
        
        else
            printf("%d\n", total);
    }
}