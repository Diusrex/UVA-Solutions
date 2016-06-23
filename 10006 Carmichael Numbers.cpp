#include <iostream>
#include <vector>

using namespace std;

// First, filter for primes
// Then, for each num, for every n greater than it, test if the carmichael doesn't hold
// This is sqrt(65005)
const int PrimeNum = 256;
const int MaxNumChecked = 65005;
bool isComp[MaxNumChecked];
bool isCar[MaxNumChecked];

int main()
{
    // Calculated using Korselt's criterion
    for (int i = 3; i < MaxNumChecked; i += 2)
        isCar[i] = true;

    for (int i = 3; i < MaxNumChecked; i += 2)
    {
        // Means is still prime
        if (!isComp[i])
        {
            isCar[i] = false;
            for (int j = 3 * i; j < MaxNumChecked; j += 2*i)
            {
                isComp[j] = true;
                if ((j / i) % i == 0 || // Contains the factor i twice
                    (j - 1) % (i - 1) != 0) // i - 1 | j - 1 is not true
                    isCar[j] = false;
            }
        }
    }

    int n;
    while (cin >> n, n)
    {
        if (isCar[n])
            cout << "The number " << n << " is a Carmichael number.\n";
        else
            cout << n << " is normal.\n";
    }
}
