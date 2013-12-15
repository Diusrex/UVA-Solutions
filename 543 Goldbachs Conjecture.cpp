#include <iostream>
#include <vector>

using namespace std;

// Needs to be faster
    // Binary search?

// 1 to num
int main()
{
    vector<bool> isPrime(1000600, true);
    vector<int> primes;
    
    for (int i = 2; i < 1000600; ++i)
    {
        if (isPrime[i])
        {
            for (int q = 2 * i; q < 1000600; q += i)
               isPrime[q] = false;
            
            primes.push_back(i);
        }
    }
    
    int num;
    cin >> num;
    
    while (num)
    {
        // Determine high number
        int top(primes.size() - 1), bottom(0);
        int mid;
        
        while ((mid = (top - bottom) / 2 + bottom) != bottom)
        {
            // minumum
            if (primes[mid] + 2 > num)
                top = mid;
            else
                bottom = mid;
        }
        
        int high = mid;
        
        high++;
        
        
        while (primes[high] + primes[mid] != num)
        {
            --high;
            int diff = num - primes[high];
            
            top = high + 1;
            bottom = 0;
        
            while ((mid = (top - bottom) / 2 + bottom) != bottom)
            {
                if (primes[mid] > diff)
                    top = mid;
                else
                    bottom = mid;
            }
        }   
        
        cout << num << " = " << primes[mid] << " + " << primes[high] << '\n';
        cin >> num;
    }
}