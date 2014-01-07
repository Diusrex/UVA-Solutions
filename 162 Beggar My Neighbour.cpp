#include <cstdio>

#define currentCard cardValues[cPlayer][spotIn[cPlayer]]

// Player is at the top of the deck. Stack is at next space to be added to.
char cardValues[2][52], stack[52], temp;
int numCards[2], spotIn[2], stackNum, stackSpot, cPlayer;

int failedToPlay;

// Returns true if callee should get all cards
bool HandleCheck(int tNum) 
{
    bool returnV(true);
    
    cPlayer = 1 - cPlayer;
    
    for (int i = 0; i < tNum; ++i)
    {
        if (numCards[cPlayer] == 0)
        {
            failedToPlay = cPlayer;
            return false;
        }
        
        int num;
        
        switch (currentCard)
        {
            case 'J':
                num = 1;
                break;
                
            case 'Q':
                num = 2;
                break;
                
            case 'K':
                num = 3;
                break;
                
            case 'A':
                num = 4;
                break;
                
            default:
                num = 0;
        }
        
        stack[stackSpot] = currentCard;
        
        
        stackSpot = (stackSpot + 1) % 52;
            
        ++stackNum;
        
        --numCards[cPlayer];
        
        spotIn[cPlayer] = (spotIn[cPlayer] + 1) % 52;
        
        if (num)
        {            
            returnV = false;
            
            if (!HandleCheck(num))
                break;
            
            else
            {
                cPlayer = 1 - cPlayer;
                
                int tempSpotP = (spotIn[cPlayer] + numCards[cPlayer]) % 52;
                
                int tempSpotS = (stackSpot - stackNum + 52) % 52;
                numCards[cPlayer] += stackNum;
                
                while (stackNum--)
                {
                    cardValues[cPlayer][tempSpotP] = stack[tempSpotS++];
                    
                    ++tempSpotP;
                    if (tempSpotP == 52)
                        tempSpotP = 0;
                        
                    if (tempSpotS == 52)
                        tempSpotS = 0;
                }
                
                stackNum = stackSpot = 0;
                i = -1;
                tNum = 1;
            }
        }
    }
    
    return returnV;
}

int main()
{
    // dealer is 1
    
    
    while (scanf(" %c", &temp), temp != '#')
    {
        scanf("%c %*c %c", &cardValues[0][25], &cardValues[1][25]);
        
        for (int i = 24; i >= 0; --i)
            scanf(" %*c %c %*c %c", &cardValues[0][i], &cardValues[1][i]);
            
        numCards[0] = numCards[1] = 26;
        stackSpot = spotIn[0] = spotIn[1] = stackNum = 0;
        cPlayer = 1;
        failedToPlay = -1;
        
        while (failedToPlay == -1)
        {
            HandleCheck(1);
        }
        
        printf ("%d %2d\n", 1 + failedToPlay, numCards[1 - failedToPlay]);
    }   
}