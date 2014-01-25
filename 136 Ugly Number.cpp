#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    long long numbers[1510];
    
    numbers[0] = 1;
    
    int i2(0), i3(0), i5(0);
    long long cTwo(2), cThree(3), cFive(5);
    
    int pos = 1;
    
    for (; pos < 1500; ++pos)
    {
        numbers[pos] = min(cTwo, min(cThree, cFive));
        
        if (cTwo == numbers[pos])
        {
            ++i2;
            cTwo = numbers[i2] * 2;
        }
        
        if (cThree == numbers[pos])
        {
            ++i3;
            cThree = numbers[i3] * 3;
        }
        
        if (cFive == numbers[pos])
        {
            ++i5;
            cFive = numbers[i5] * 5;
        }
    }
    
    printf("The 1500'th ugly number is %d.\n", numbers[pos - 1]);
}