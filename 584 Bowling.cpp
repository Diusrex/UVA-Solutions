#include <cstdio>


int handle(char current, char previous, char twoPrevious, bool addOwnScore)
{
    int baseScore(0);
    int score = 0;
    
    if (current == 'X')
    {
        baseScore = 10;
    }
    
    else if (current == '/')
    {
        baseScore = 10 - (previous - '0');
    }
    
    else
    {
        baseScore = current - '0';
    }
    
    if (addOwnScore)
        score = baseScore;
    
    if (previous == '/' || previous == 'X')
        score += baseScore;
    
    if (twoPrevious == 'X')
        score += baseScore;
    
    return score;
}

const int countedThrows = 20;

int main()
{
    char first;
    
    while (scanf(" %c", &first), first != 'G')
    {
        char current = first, previous = ' ', twoPrevious = ' ';
        
        int score;
        
        score = handle(current, previous, twoPrevious, true);
        previous = current;
        
        int bonusThrows = 0;
        
        for (int i = (current == 'X') ? 2 : 1; i < countedThrows; ++i)
        {
            scanf(" %c", &current);
            
            score += handle(current, previous, twoPrevious, true);
            twoPrevious = previous;
            previous = current;
            
            if (current == 'X')
            {
                if (i == 18) // First throw of the last round
                    bonusThrows = 2;
                
                ++i;
            }
            
            if (current == '/' && i == 19)
                bonusThrows = 1;
        }
        
        for (int i = 0; i < bonusThrows; ++i)
        {
            scanf(" %c", &current);
            score += handle(current, previous, twoPrevious, false);
            twoPrevious = previous;
            
            previous = current; // The just thrown ball does not improve score
            if (previous == 'X')
                previous = ' ';
        }
        
        printf("%d\n", score);
    }

}