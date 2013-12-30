#include <cstdio>

int main()
{   
    int T, N, move[101], posInMove, position, check;
    
    char s[100];
    
    scanf("%d", &T);
    
    while (T--)
    {
        posInMove = position = 0;
        
        scanf("%d", &N);
        
        while (N--)
        {
            scanf("%s", s);
            
            if (s[0] == 'L')
            {
                position += move[posInMove] = -1;
            }
            else if (s[0] == 'R')
            {
                position += move[posInMove] = 1;
            }
            else 
            {
                scanf("%*s %d", &check);
                
                position += move[posInMove] = move[check - 1];
            }
            
            ++posInMove;
        }
        
        printf("%d\n", position);
    }
}