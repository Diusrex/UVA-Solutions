#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    vector<int> primes(4792);
    vector<bool> isPrime(46340, true);
    
    primes[0] = 2;
    int pos(1);
    
    for (long long i = 3; i < 46340; i += 2)
    {
        if (isPrime[i])
        {
            for (long long j = i * i; j < 46340; j += i)
            {
                isPrime[j] = false;
            }
            
            primes[pos] = i;
            ++pos;
        }
    }
    
    int num;
    while (scanf("%d", &num), num != 0)
    {
        printf("%d =", num);
        
        bool anotherOccurance(false);
        
        
        if (num < 0)
        {
            num *= -1;
            printf(" -1");
            anotherOccurance = true;
        }
        
        else if (num == 1)
            printf(" 1");
            
        for (int pos = 0; primes[pos] * primes[pos] <= num && pos < 4792; ++pos)
        {
            while (num % primes[pos] == 0)
            {
                if (anotherOccurance)
                    printf(" x %d", primes[pos]);
                else
                    printf(" %d", primes[pos]);
                    
                anotherOccurance = true;
                num /= primes[pos];
            }
        }
        
        if (num > 1)
        {
            if (anotherOccurance)
                printf(" x %d", num);
            else
                printf(" %d", num);
        }
        
        printf("\n");
    }
}