#include <cstdio>

int main()
{
    int T, pos, current, Y;
    
    char cards[52][3];
    
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        Y = 0;
        pos = 52 - 25;
        
        for (int i = 0; i < 52; ++i)
            scanf("%s", cards[i]);
        
        /*
        for (int i = 0; i < 3; ++i, --pos)
        {
            current = cards[pos][0] - '0';
            if (current < 2 || current > 9)
                current = 10;
            
            printf("Current is %d from %s\n", current, cards[pos]);
            
            pos -= (10 - current);
            Y += 10;
        }
        
        if (Y >= 52 - 25)
            Y += 3;
        */
        printf("Case %d: %s\n", t, cards[32]);

    }
}