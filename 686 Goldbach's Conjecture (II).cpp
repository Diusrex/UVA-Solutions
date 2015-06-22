#include <iostream>
#include <vector>

using namespace std;

const int Max_Val = 32769;
const int Num_Primes = 3512;

bool isComp[Max_Val];
int primes[Num_Primes];

void CalculateAllPrimes()
{
    int pos = 0;
    primes[pos++] = 2;
    int i;
    for (i = 3; i * i <= Max_Val; i += 2)
    {
        if (!isComp[i])
        {
            primes[pos++] = i;
            for (int j = i * i; j < Max_Val; j += i)
                isComp[j] = true;
        }
    }
    
    for (; i < Max_Val; i += 2)
        if (!isComp[i])
            primes[pos++] = i;
}

int GetCount(int n)
{
    int count = 0;
    int l = 0, t = Num_Primes - 1;
    
    while (l <= t)
    {
        if (primes[l] + primes[t] == n)
        {
            ++count;
            ++l;
            --t;
        }
        else if (primes[l] + primes[t] < n)
            ++l;
        else
            --t;
    }
    
    return count;
}

int main()
{
    CalculateAllPrimes();
    
    int n;
    while (cin >> n, n)
    {
        cout << GetCount(n) << '\n';
    }
}