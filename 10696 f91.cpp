#include <cstdio>

int f91(int num)
{
    if (num <= 100)
        return f91(f91(num + 11));
    else
        return num - 10;
}

int main()
{
    int num;
    while (scanf("%d", &num), num)
    {
        printf("f91(%d) = %d\n", num, f91(num));
        
    }
}