#include <cstdio>
    
int main()
{
    unsigned int num;
    
    while (scanf("%u", &num), num)
    {
        unsigned int a = 0, b = 0;
        
        bool addToA = true;
        unsigned int toAdd = 1;
        
        while (num)
        {
            if (num & 1)
            {               
                if (addToA)
                    a += toAdd;
                else
                    b += toAdd;
                    
                addToA = !addToA;
            }
            
            toAdd *= 2;
            num /= 2;
        }
        
        printf("%u %u\n", a, b);
    }
}