#include <cstdio>

int main()
{
    char input[20];
    
    scanf("%s", input);
    
    for (int t = 1; input[0] != '*'; ++t, scanf("%s", input))
    {
        if (input[0] == 'H')
            printf("Case %d: Hajj-e-Akbar\n", t);
        else
            printf("Case %d: Hajj-e-Asghar\n", t);
    }

}