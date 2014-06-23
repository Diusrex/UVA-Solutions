#include <cstdio>

// 1 means firstWon, 2 means 
int GetResult(char firstPlay, char secondPlay)
{
    if (firstPlay == secondPlay)
        return 0;
    
    if (firstPlay == 'r')
    {
        if (secondPlay == 's')
            return 1;
        else
            return -1;
    }
    
    else if (firstPlay == 'p')
    {
        if (secondPlay == 'r')
            return 1;
        else
            return -1;
    }
    
    else
    {
        if (secondPlay == 'p')
            return 1;
        else
            return -1;
    }
}

int main()
{
    int numPlayers, numGames;
    int numLoss[101], numWins[101];
    
    char firstPlay[15], secondPlay[15];
    
    bool isFirst = true;
    
    while (scanf("%d", &numPlayers) == 1)
    {
        if (numPlayers == 0)
            break;
            
        scanf("%d", &numGames);
        
        for (int i = 1; i <= numPlayers; ++i)
            numLoss[i] = numWins[i] = 0;
        
        int first, second;
        
        numGames = numGames * numPlayers * (numPlayers -1) / 2;
        
        for (int i = 0; i < numGames; ++i)
        {
            scanf("%d %s %d %s", &first, firstPlay, &second, secondPlay);
            
            int result = GetResult(firstPlay[0], secondPlay[0]);
            
            if (result == 1)
            {
                numWins[first]++;
                numLoss[second]++;
            }
            else if (result == -1)
            {
                numWins[second]++;
                numLoss[first]++;
            }
        }
        
        if (!isFirst)
            printf("\n");
            
        isFirst = false;
        
        for (int i = 1; i <= numPlayers; ++i)
        {
            if (numLoss[i] + numWins[i] == 0)
                printf("-\n");
            else
                printf("%.3f\n", (1.0 * numWins[i]) / (numLoss[i] + numWins[i]));
        }
    }
}