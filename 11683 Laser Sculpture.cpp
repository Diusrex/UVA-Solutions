#include <cstdio>

int wantedSize[10010];

int main()
{
    int height, length;
    
    while (scanf("%d %d", &height, &length), height)
    {
        int count(0);
        
        scanf("%d", &wantedSize[0]);
        count += height - wantedSize[0];
        
        for (int i = 1; i < length; ++i)
        {
            scanf("%d", &wantedSize[i]);
            
            if (wantedSize[i] != height)
            {
                int temp = wantedSize[i - 1] - wantedSize[i];
                
                if (temp > 0)
                    count += temp;
               
            }
        }
        
        printf("%d\n", count);
        
    }
}