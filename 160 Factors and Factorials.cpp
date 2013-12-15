#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void GoThroughAllFactors(int currentNumber, vector<int>& factors, const vector<int>& primes, int& farthestPos)
{
    if (currentNumber == 1)
        return;
    
    int temp(currentNumber);
    int currentPos(0);
    while (temp != 1)
    {
        if (temp % primes[currentPos] == 0)
        {
            temp /= primes[currentPos];
            ++factors[currentPos];
        }
        
        else
            ++currentPos;
        
    }
    
    if (currentPos > farthestPos)
        farthestPos = currentPos;
        
    GoThroughAllFactors(currentNumber -1, factors, primes, farthestPos);
}


int main()
{
    vector<int> primes;
    vector<bool> isPrime(101, true);
    
    for (int i = 2; i < 101; ++i)
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int z = 2*i; z < 101; z += i)
                isPrime[z] = false;
        }
    
    int currentNumber;
    cin >> currentNumber;
    
    while (currentNumber != 0)
    {
        vector<int> factors(primes.size(), 0);
        
        int farthestPos(-1);  
    
        GoThroughAllFactors(currentNumber, factors, primes, farthestPos);
        
        cout << setw(3) << currentNumber << "! ="; 
        
        for (int i = 0; i <= farthestPos; ++i)
        {
            if (i % 15 == 0 && i != 0)
                cout << "\n      ";
                
            cout << setw(3) << factors[i];
        }
        cout << '\n';
        cin >> currentNumber;
    }
}