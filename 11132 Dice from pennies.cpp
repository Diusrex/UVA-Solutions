#include <cstdio>
#include <iostream>

using namespace std;

int getSize(int diceNum)
{
    int size(0);
    
    do
    {
        diceNum /= 2;
        ++size;
    } while (diceNum);
    
    return size;
}


int main()
{
    int num, die, csize, multiplyer, total, current;
    
    bool valid;
    
    string input;
    
    while (scanf("%d %*c %d", &num, &die), num + die)
    {
        csize = getSize(die - 1);
        
        cin >> input;
        total = 0; 
        
        for (int start = csize - 1; start < input.size() && num; start += csize)
        {
            current = 1;
            
            multiplyer = 1;
            
            for (int pos = 0; pos < csize; ++pos, multiplyer *= 2)
            {
                if (input[start - pos] == 'T')
                    current += multiplyer;
            }
            
            if (current <= die)
            {
                total += current;
                --num;
            }
            
        }
        
        if (!num)
            printf("%d\n", total);
        else
            printf("-1\n");
    }
    
}