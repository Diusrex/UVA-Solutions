#include <cstdio>
#include <vector>

using namespace std;

vector<int> GetPrimes()
{
    vector<bool> isPrime(1000, true);
    vector<int> primes;
    primes.push_back(1);
    primes.push_back(2);
    
    for (int i = 3; i < 1000; i += 2)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j < 1000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    
    return primes;
}

int GetHighest(const vector<int>& allPrimes, const int & n)
{
    int pos = 0;
    for (; pos < allPrimes.size() && allPrimes[pos] <= n; ++pos);
    
    return pos;
}

int main()
{
    vector<int> allPrimes = GetPrimes();
    
    int n, c;
    
    //printf("Size is %d\n", allPrimes.size());
    
    while (scanf("%d%d", &n, &c) == 2)
    {
        int highestPos = GetHighest(allPrimes, n);
        
        printf("%d %d:", n, c, highestPos, allPrimes[highestPos]);
        
        // Odd
        if (highestPos & 1)
        {
            if (c * 2 - 1 >= highestPos)
            {
                for (int i = 0; i < highestPos; ++i)
                {
                    printf(" %d", allPrimes[i]);
                }
            }
            else
            {
                int middle = highestPos / 2;
                
                --c;
                
                for (int i = middle - c; i <= middle + c; ++i)
                    printf(" %d", allPrimes[i]);
            }
        }
        
        else
        {
            if (c * 2 >= highestPos)
            {
                for (int i = 0; i < highestPos; ++i)
                {
                    printf(" %d", allPrimes[i]);
                }
            }
            
            else
            {
                int middle = highestPos / 2;
                for (int i = middle - c; i < middle + c; ++i)
                    printf(" %d", allPrimes[i]); 
            }
        }
        
        printf("\n\n");
    }
}
