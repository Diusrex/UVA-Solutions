#include <cstdio>

int main()
{
    int T, num, top, bot, diff;
    
    scanf("%d", &T);
    
    bool valid;
    
    char seperator[2];
    seperator[0] = seperator[1] = '\0';
    
    while (T--)
    {
        valid = true;
        
        scanf("%d %d %d", &num, &top, &bot);
        
        num--;
        
        diff = top - bot;
        
        while (num--)
        {
            scanf("%d %d", &top, &bot);
            
            if (valid && top - bot != diff)
                valid = false;
        }
    
        if (valid)
            printf("%syes\n", seperator);
        else
            printf("%sno\n", seperator);
            
        seperator[0] = '\n';
    }

}