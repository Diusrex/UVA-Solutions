#include <cstdio>

using namespace std;

// All times are in minutes

const int FULL_DAY = 60 * 24;

int main()
{
    int h1, m1, h2, m2;
    
    while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2), h1 + m1 + h2 + m2)
    {
        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;
        
        if (t1 > t2)
            t2 += FULL_DAY;
        
        printf("%d\n", t2 - t1);
    }
}