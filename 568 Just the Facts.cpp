#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_NUM = 10000;

int preCalculated[MAX_NUM + 1];

inline void updatePrecalculated(int N, int lastDigit, int twos)
{
    while (twos--)
        lastDigit = (2 * lastDigit) % 10;
    
    preCalculated[N] = lastDigit;
}

int preCalculate()
{
    int lastDigit = 1, multiple = 2, twos = 0;
    preCalculated[0] = 1;
    preCalculated[1] = 1;
        
    for (; multiple <= MAX_NUM; ++multiple)
    {
        int temp = multiple;
        while (temp % 2 == 0)
        {
            ++twos;
            temp /= 2;
        }
        
        while (temp % 5 == 0)
        {
            --twos;
            temp /= 5;
        }
        
        lastDigit = (lastDigit * temp) % 10;
        
        updatePrecalculated(multiple, lastDigit, twos);
    }
}

int main()
{
    preCalculate();
    int N;
    while (cin >> N)
    {
        cout << setw(5) << N << " -> " << preCalculated[N] << '\n';
    }
}