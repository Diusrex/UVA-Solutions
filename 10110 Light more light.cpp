#include <cstdio>
#include <cmath>

int main()
{
    unsigned int num, root;
    
    while (scanf("%u", &num), num)
    {
        root = (unsigned int) sqrt(num);
        
        if (root * root == num)
            printf("yes\n");
        else
            printf("no\n");
    }
}