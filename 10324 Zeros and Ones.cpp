// Please note, this program passed with 2.949 s out of 3 max, so it is not very efficient...
#include <cstdio>

int main()
{
    char s[1000005];
    
    int n, a, b, temp, t(1);
    bool valid;
    
    while (scanf("%s %d", s, &n) == 2)
    {
        printf("Case %d:\n", t);
        ++t;
        
        while (n--)
        {
            scanf("%d%d", &a, &b);
            if (b < a)
            {
                temp = a;
                a = b;
                b = temp;
            }
            
            valid = true;
            
            for (int i = a; i < b; ++i)
                if (s[i] != s[i + 1])
                    valid = false;
            
            if (valid)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}