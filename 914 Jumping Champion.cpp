#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int BIGGEST_DIFF = 115;
int FindPos(const vector<int>& primes, int valueWanted)
{
    int min(0), max(primes.size() - 1), mid;
    
    while (min < max)
    {
        mid = (min + max) / 2;
        
        if (primes[mid] > valueWanted)
            max = mid;
        else if (primes[mid] < valueWanted)
            min = mid + 1;
        else
            return mid;
    }
    
    return min;
}

int main()
{
    vector<bool> isPrime(1000000, true);
    vector<int> primes;
    primes.push_back(2);
    
    for (long long i = 3; i < 1000000; i += 2)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            
            long long doubleI = i * 2;
            
            for (long long j = i * i; j < 1000000; j += doubleI)
                isPrime[j] = false;
            
        }
    }
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int l, u;
        scanf("%d%d", &l, &u);
        
        int min = FindPos(primes, l), max = FindPos(primes, u);
        
        if (primes[min] < l)
            ++min;
        
        if (primes[max] > u)
            --max;
            
        vector<int> diffCount(BIGGEST_DIFF, 0);
        
        for (int i = min + 1; i <= max; ++i)
        {
            ++diffCount[primes[i] - primes[i - 1]];
        }
        
        int highest = 0, number = -1;
        
        for (int i = 0; i < BIGGEST_DIFF; ++i)
        {
            if (diffCount[i] > highest)
            {
                highest = diffCount[i];
                number = i;
            }
            
            else if (diffCount[i] == highest)
                number = -1;
        }
        
        if (number == -1)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %d\n", number);
    }
}
