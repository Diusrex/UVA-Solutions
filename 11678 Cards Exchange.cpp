#include <cstdio>
#include <map>

using namespace std;

int main()
{
    map<int, bool> cards;
    
    int aCards, bCards, current, aCount, bCount;
    
    while (scanf("%d %d", &aCards, &bCards), aCards && bCards)
    {
        aCount = bCount = 0;
        cards.clear();
        
        for (int i = 0; i < aCards; ++i)
        {
            scanf("%d", &current);
            
            if (cards.find(current) == cards.end())
            {
                ++aCount;
                cards[current] = true;
            }
        }
        
        for (int i = 0; i < bCards; ++i)
        {
            scanf("%d", &current);
            
            map<int, bool>::iterator iter = cards.find(current);
            
            if (iter == cards.end())
            {
                cards[current] = false;
                ++bCount;
            }
            
            else if (iter->second)
            {
                iter->second = false;
                --aCount;
            }   
        }
        
        printf("%d\n", aCount < bCount ? aCount : bCount);
    }

}