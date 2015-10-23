#include <cstdio>

int main()
{
    // Fairly simple to pre-calculate. Can just calculate all primes in a table, then check if all orderings of the digits are prime.
    int anagramic[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
    int size = 22;
    
    
    int wanted;
    
    while (scanf("%d", &wanted), wanted)
    {
        int best = size;
        
        for (int i = size - 1; i >= 0 && anagramic[i] > wanted; --i, --best);
        
        if (best < size)
        {
            int max = 1;
            
            while (wanted)
            {
                wanted /= 10;
                max *= 10;
            }
            
            if (anagramic[best] < max)
                printf("%d\n", anagramic[best]);
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }
}
