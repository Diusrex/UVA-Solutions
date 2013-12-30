#include <cstdio>
#include <algorithm>

int main()
{
    int first, second, one, two;
    
    while (scanf("%d%d", &first, &second), first != -1)
    {
        if (first > second)
        {
            one = first - second;
            two = second + 100 - first;
            
        }
        else
        {
            one = second - first;
            two = first + 100 - second;
        }
        printf("%d\n", std::min(one, two));
    }
}