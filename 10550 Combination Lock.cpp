#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int start, first, second, third;
    
    scanf("%d %d %d %d", &start, &first, &second, &third);
    
    while (start || first || second || third)
    {
        printf("%d\n", 1080 + ((start - first + 40) % 40 + (second - first + 40) % 40 + (second - third + 40) % 40) * 9);
        
        scanf("%d %d %d %d", &start, &first, &second, &third);
    }
}