#include <cstdio>

int main()
{
    int T, temp;
    bool valid;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        valid = true;
        
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &temp);
            if (temp > 20)
                valid = false;
        }
        
        if (!valid)
            printf("Case %d: bad\n", t);
        else
            printf("Case %d: good\n", t);
    }

}