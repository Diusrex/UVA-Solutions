#include <cstdio>
#include <string.h>

int main()
{
    int max, min, guess;
    
    bool valid;
    char input[12];
    
    max = 11;
    min = 0;
    
    valid = true;
    
    while (scanf("%d", &guess), guess)
    {
        scanf("%*s %s", input);
        
        if (strcmp(input, "high") == 0)
        {
            if (guess <= min)
                valid = false;
            
            if (guess < max)
                max = guess;
        }
        
        else if (strcmp(input, "low") == 0)
        {
            if (guess >= max)
                valid = false;
            
            if (guess > min)
                min = guess;
        }
        
        else
        {
            if (guess > min && guess < max && valid)
            {
                printf("Stan may be honest\n");
            }
            
            else
            {
                printf("Stan is dishonest\n");
            }
        
            valid = true;
            min = 0;
            max = 11;
        }
    }
}