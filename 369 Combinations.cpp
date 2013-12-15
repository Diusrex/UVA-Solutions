#include <iostream>
#include <vector>

using namespace std;


long myPow(int b, int e)
{
    //cout << b << " to the power of " << e << " is: ";
    long value(1), v(b);
    
    while (e)
    {
        if (1 & e)
            value *= v;
        
        v *= v;
        e >>= 1;
    }
    
    //cout << value << '\n';
    
    return value;
}

// factors should be size (allPrimes.size())
void DeterminePrimeFactors(const vector<int> allPrimes, vector<int>& factors, int number)
{
    for (int i = 2; i <= number; ++i)
    {
        int pos(0);
        int temp(i);
        while (temp != 1)
        {
            if (temp % allPrimes[pos] == 0)
            {
                temp /= allPrimes[pos];
                ++factors[pos];
            }
            
            else
                ++pos;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<bool> primeNumbers(101, true);
    vector<int> thePrimes;
    
    for (int i = 2; i < 100; ++i)
        if (primeNumbers[i])
        {
            for (int q = i * 2; q < 101; q += q)
                primeNumbers[q] = false;
                
            thePrimes.push_back(i);
        }
        
    while (n != 0)
    {
        int diff = n - m;
        if (diff == 0)
            diff = 1;
            
        vector<int> nTotalFactors(thePrimes.size()), mTotalFactors(thePrimes.size()), diffTotalFactors(thePrimes.size());
        DeterminePrimeFactors(thePrimes, nTotalFactors, n);
        DeterminePrimeFactors(thePrimes, mTotalFactors, m);
        DeterminePrimeFactors(thePrimes, diffTotalFactors, diff);
        
        /*
        for (int i = 0; i < thePrimes.size(); ++i)
            cout << nTotalFactors[i] << ' ';
        cout << '\n';
        */
        for (int i = 0; i < thePrimes.size(); ++i)
        {
            //cout << mTotalFactors[i] << ' ';
            nTotalFactors[i] -= mTotalFactors[i];
        }    
        //cout << '\n';  

        for (int i = 0; i < thePrimes.size(); ++i)
        {
            //cout << diffTotalFactors[i] << ' ';  
            nTotalFactors[i] -= diffTotalFactors[i];
        }
        //cout << '\n';
        
        long value(1);
        
        for (int i = 0; i < thePrimes.size(); ++i)
            value *= myPow(thePrimes[i], nTotalFactors[i]);
        
        
        cout << n << " things taken " << m << " at a time is " << value << " exactly.\n";    
        
        cin >> n >> m;
    }

}