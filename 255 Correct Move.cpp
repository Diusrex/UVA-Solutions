#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int king, queen, queenTo, diff;
    
    
    while (scanf("%d %d %d", &king, &queen, &queenTo) == 3)
    {
        if (king == queen)
        {
            printf("Illegal state\n");
            continue;
        }
    
        if (((queenTo - queen) % 8 != 0 && queenTo / 8 != queen / 8) || queen == queenTo)
        {
            printf("Illegal move\n");
            continue;
        }
        
        if (((king - queen) % 8 == 0 && (king - queenTo) % 8 == 0) || (king / 8 == queen / 8 && king  / 8 == queenTo / 8))
        {
            if (king <= max(queen, queenTo) && king >= min(queen, queenTo))
            {
                printf("Illegal move\n");
                continue;
            }
        }
        
        diff = max(king, queenTo) - min(king, queenTo);
        
        if (diff == 8 || (diff == 1 && king / 8 == queenTo / 8))
        {
            printf("Move not allowed\n");
            continue;
        }
        
        if ((king == 0 && queenTo == 9) || (king == 7 && queenTo == 14) || (king == 56 && queenTo == 49) || (king == 63 && queenTo == 54))
            printf("Stop\n");
        
        else
            printf("Continue\n");
    }
}