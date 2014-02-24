#include <cstdio>

int main()
{
    int top, bottom, east, west, north, south, temp;
    
    int T;
    
    char input[7];
    
    while (scanf("%d", &T), T)
    {
        top = 1; bottom = 6;
        north = 2; south = 5;
        east = 4; west = 3;
        
        while (T--)
        {
            scanf("%s", input);
            
            temp = top;
            
            if (input[0] == 'n')
            {
                top = south;
                south = bottom;
                bottom = north;
                north = temp;
            }
            else if (input[0] == 'e')
            {
                top = west;
                west = bottom;
                bottom = east;
                east = temp;
            }
            else if (input[0] == 's')
            {
                top = north;
                north = bottom;
                bottom = south;
                south = temp;
            }
            else
            {
                top = east;
                east = bottom;
                bottom = west;
                west = temp;
            }
        }
        
        printf("%d\n", top);
    }
}