#include <cstdio>

using namespace std;

int main()
{
    int T, f, s, t;
    
    scanf("%d", &T);
    
    for (int round = 1; round <= T; ++round)
    {
        scanf("%d %d %d", &f, &s, &t);
        
        printf("Case %d: ", round);
        
        if ((f > s && f < t) || (f > t && f < s))
            printf("%d\n", f);
        else if ((s > f && s < t) || (s < f && s > t))
            printf("%d\n", s);
        else
            printf("%d\n", t);
        
        
    
    }

}