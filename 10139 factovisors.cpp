#include <cstdio>

// is n / p + n / p^2 + n / p ^3 + n / p ^ 4 until n / p ^ x is 0

bool CheckIfPossible(int n, int prime, int count)
{
    long primeValue = prime;
    
    while (n / primeValue && count > 0)
    {
        count -= n / primeValue;
        primeValue *= prime;
    }
    
    return count <= 0;
}


int main()
{
    int n, d, count, temp;
    bool isDivisor;
    
    while (scanf("%d%d", &n, &d) == 2)
    {
        temp = d;
        isDivisor = true;
        
        for (int i = 2; i * i <= d && isDivisor; ++i)
        {
            count = 0;
            
            while (d % i == 0)
            {
                d /= i;
                ++count;
            }
            
            if (count > 0)
                isDivisor = CheckIfPossible(n, i, count);
        }
        
        if (d > 1 && isDivisor)
        {
            isDivisor = CheckIfPossible(n, d, 1);
        }
        
        printf("%d %s %d!\n", temp, isDivisor ? "divides" : "does not divide", n);
    }
}