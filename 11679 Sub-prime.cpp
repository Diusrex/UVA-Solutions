#include <cstdio>

int main()
{
    int B, N, owe, owed, amount;
    int owes[20];
    
    scanf("%d %d", &B, &N);
    
    while (B)
    {
        // sets up how much they have in credit or whatever
        for (int i = 0; i < B; ++i)
            scanf("%d", &owes[i]);
        
        
        while (N--)
        {
            scanf("%d %d %d", &owe, &owed, &amount);
            
            owes[owe - 1] -= amount;
            owes[owed - 1] += amount;
        }
        
        bool positive(true);
        
        for (int i = 0; i < B; ++i)
            if (owes[i] < 0)
                positive = false;
        
        if (positive)
            printf("S\n");
        else
            printf("N\n");
        
        scanf("%d %d", &B, &N);
    }

}