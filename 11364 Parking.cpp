#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, numStore, min, max, temp;
    
    cin >> T;
    
    while (T--)
    {
        min = 99; max = 0;
        cin >> numStore;
        
        for (int i = 0; i < numStore; ++i)
        {
            scanf("%d", &temp);
            
            if (temp < min)
                min = temp;
            if (temp > max)
                max = temp;
        }
        
        printf("%d\n", (max - min) * 2);
    }
}