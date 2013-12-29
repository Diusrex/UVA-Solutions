#include <cstdio>

int main()
{
    printf("Lumberjacks:\n");
    int N, current, previous;
    scanf("%d", &N);
    
    bool determined, increasing, valid;
    
    while (N--)
    {
        valid = true;
        determined = false;
        
        scanf("%d", &previous);
        
        for (int i = 0; i < 9; ++i)
        {
            scanf("%d", &current);
            
            if (!determined)
            {
                determined = true;
                
                if (previous == current)
                    determined = false;
                    
                else if (current > previous)
                    increasing = true;
                    
                else
                    increasing = false;
                
                previous = current;
            }
            
            else if (valid)
            {
                if (current > previous && !increasing)
                    valid = false;
                
                else if (current < previous && increasing)
                    valid = false;
                previous = current;
            }
            
            
        }
        
        if (!valid)
            printf("Unordered\n");
        else
            printf("Ordered\n");
    }
}