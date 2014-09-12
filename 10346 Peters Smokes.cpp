#include <cstdio>

int main()
{
    int n, k;
    
    while (scanf("%d %d", &n, &k) == 2)
    {
        int count(0), b(0);
        while (n)
        {
            count += n;
            int t = n + b;
            n = t / k;
            b = t % k;
        }
        
        printf("%d\n", count);
    }

}