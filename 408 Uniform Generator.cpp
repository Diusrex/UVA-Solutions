#include <cstdio>

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    
    return gcd(y, x % y);
}


int main()
{
    int x, y;
    
    while (scanf("%d%d", &x, &y) == 2)
    {
        printf("%10d%10d    %s\n\n", x, y, gcd(x, y) == 1 ? "Good Choice" : "Bad Choice");
    }
}