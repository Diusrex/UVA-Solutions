#include <cstdio>

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        bool winner = true;
        
        while (n > 1)
        {
            if (winner)
            {
                bool increase = n % 9;
                n /= 9;
                if (increase)
                    ++n;
            }
            
            else
            {
                bool increase = n % 2;
                n /= 2;
                if (increase)
                    ++n;
            }
            
            winner = !winner;
        }
        
        if (!winner)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }
}