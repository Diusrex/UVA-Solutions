#include <cstdio>

int main()
{
    char direction[3], input[3];
    direction[2] = '\0';
    int num;
    
    while (scanf("%d", &num), num)
    {
        direction[0] = '+'; direction[1] = 'x';
        --num;
        while (num--)
        {
            scanf("%s", input);
            
            if (input[0] == 'N')
                continue;
               
            if (direction[1] == 'x')
            {
                direction[1] = input[1];
                direction[0] = (input[0] == direction[0]) ? '+' : '-';
            }
            
            else if (input[1] == 'z')
            {
                if (direction[1] == 'z')
                {
                    direction[1] = 'x';
                    
                    if (direction[0] != input[0])
                        direction[0] = '+';
                    else
                        direction[0] = '-';
                }
            }
            
            else
            {
                if (direction[1] == 'y')
                {
                    direction[1] = 'x';
                    
                    if (direction[0] != input[0])
                        direction[0] = '+';
                    else
                        direction[0] = '-';
                }
            }
        }
        
        printf("%s\n", direction);
    }
}