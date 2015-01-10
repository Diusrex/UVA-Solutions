#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        int hr, min;
        char temp;
        
        scanf("%d%c%d", &hr, &temp, &min);
        
        min = (60 - min) % 60;
        
        hr = 12 - hr;
        if (min != 0)
            --hr;
        
        hr = (hr + 12) % 12;
        if (hr == 0)
            hr = 12;
        printf("%02d:%02d\n", hr, min);
    }
}