#include <cstdio>

int GetNumOnes(int num)
{
    int count = 0;
    
    while (num)
    {
        count += (num & 1);
        num >>= 1;
    }
    
    return count;
}

char* GetBits(int num)
{
    static char out[32];
    out[31] = '\0';
    
    int pos = 31;
    while (num)
    {
        out[--pos] = '0' + (num & 1);
        num >>= 1;
    }
    
    return out + pos;
}

int main()
{
    int num;
    
    while (scanf("%d", &num), num)
        printf("The parity of %s is %d (mod 2).\n", GetBits(num), GetNumOnes(num));
}