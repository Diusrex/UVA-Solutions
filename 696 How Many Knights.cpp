#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int r, c, minNum, maxNum, numbers;
    
    while (scanf("%d %d", &r, &c), r + c)
    {
        minNum = min(r, c);
        maxNum = max(r, c);
        
        
        if (minNum == 1)
           numbers = maxNum;
           
        else if (minNum == 2)
        {
            numbers = 4 * int(maxNum / 4) + 2 * min(2, maxNum % 4);
        }
        
        else
            numbers = (r * c + 1) / 2;
        
        printf("%d knights may be placed on a %d row %d column board.\n", numbers, r, c);
    }
}