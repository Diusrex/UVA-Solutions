#include <cstdio>
#include <cstring>

int recurse(int length, int count)
{
    if (length == 1)
        return count + 1;
        
    int newLength(0), oldLength(length);
    
    for (; length; length /= 10, ++newLength);
        
    return recurse(newLength, count + 1);
}


int main()
{
    char input[1000010];
    
    while (scanf("%s", input), input[0] != 'E')
    {
        if (strlen(input) == 1 && input[0] == '1')
            printf("1\n");
        else
            printf("%d\n", recurse(strlen(input), 1));
    }
}