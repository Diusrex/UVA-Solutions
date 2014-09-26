#include <cstdio>

int main()
{
    int n;
    
    while (scanf("%d", &n) == 1)
    {
        int numDigits = 1;
        int value = 1 % n;
        
        while (value)
        {
            ++numDigits;
            value = ((value * 10) + 1) % n;
        }
        
        printf("%d\n", numDigits);
    }
}