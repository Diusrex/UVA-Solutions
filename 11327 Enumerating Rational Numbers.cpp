#include <iostream>

using namespace std;

const int MAX_NUM = 200002;

int numPrimes;
int Primes[30000];

void DetermineAllPrimes()
{
    // Skips even numbers
    bool notPrime[MAX_NUM + 1] = {false};
    numPrimes = 0;
    
    Primes[numPrimes++] = 2;
    
    
    int i;
    for (i = 3; i * i < MAX_NUM && i * i > i; i += 2)
    {
        if (!notPrime[i])
        {

            Primes[numPrimes++] = i;
            for (int j = i * i; j < MAX_NUM; j += i * 2)
                notPrime[j] = true;
        }
    }
    for (; i < MAX_NUM; i += 2)
        if (!notPrime[i])
        {
            Primes[numPrimes++] = i;
        }
}

int gcd(int a, int b)
{
    if (b)
        return gcd(b, a % b);
    
    return a;
}

// From Competitive programming 3
int EulerPhi(int n)
{
    long long PF_idx = 0, PF = Primes[PF_idx], ans = n;
    
    while (PF * PF <= n)
    {
        if (n % PF == 0) ans -= ans / PF;
        while (n % PF == 0) n /= PF;
        PF = Primes[++PF_idx];
    }
    
    if (n != 1) ans -= ans / n;
    
    return ans;
}

long long countAt[MAX_NUM + 1];

int main()
{
    DetermineAllPrimes();

    countAt[0] = 0;
    countAt[1] = 1;
    countAt[2] = 2;
    
    for (int i = 2; i < MAX_NUM; ++i)
    {
        int temp = EulerPhi(i);
        countAt[i+1] = countAt[i] + temp;
    }
    
    long long n;
    while (cin >> n, n)
    {
        if (n == 1)
            cout << "0/1\n";
        else if (n == 2)
            cout << "1/1\n";
        else
        {
            int denominator = (lower_bound(countAt, countAt + MAX_NUM, n) - 1) - countAt;
            n -= countAt[denominator];
            int i;
            for (i = 1; n; ++i)
                if (gcd(i, denominator) == 1)
                    --n;
                
            cout << (i - 1) << '/' << denominator << '\n';
        }
    }
}