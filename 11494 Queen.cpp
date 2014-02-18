#include <cstdio>
#include <cmath>


int main()
{
    int fr, fc, sr, sc, dr, dc;
    
    while (scanf("%d %d %d %d", &fr, &fc, &sr, &sc), fr)
    {
        dr = std::abs(fr - sr); dc = std::abs(fc - sc);
        if (dr + dc == 0)
            printf("0\n");
        else if (dr == dc || dr == 0 || dc == 0)
            printf("1\n");
        else
            printf("2\n");
    }
}