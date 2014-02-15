#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T, r, c, num;
    char p;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf(" %c %d %d", &p, &r, &c);
        
        
        if (p == 'r')
        {
            num = min(r, c);
        }
        
        else if (p == 'k')
        {
            num = r * c / 2;
        }
        
        else if (p == 'Q')
        {
            num = min(r, c);
        }
        
        else
            num = int((r + 1) / 2) * int((c + 1) / 2);
            
        printf("%d\n", num);
    }
}