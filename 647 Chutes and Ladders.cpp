#include <cstdio>
#include <vector>

using namespace std;

int rolls[1005], moveTo[101], extraRoll[101];


int RunGame(int numberOfPlayers)
{
    vector<int> playerPositions(numberOfPlayers, 0);
    vector<bool> skippingTurn(numberOfPlayers, false);
        
    int currentPlayer = 0;
    int posInRolls = 0;
    
    while (true)
    {
        if (skippingTurn[currentPlayer])
        {
            skippingTurn[currentPlayer] = false;
            currentPlayer = (currentPlayer + 1) % numberOfPlayers;
            continue;
        }
        
        bool increment = true;
        
        if (playerPositions[currentPlayer] + rolls[posInRolls] <= 100)
        {
            playerPositions[currentPlayer] += rolls[posInRolls];
            
            if (moveTo[playerPositions[currentPlayer]] != -1)
            {
               playerPositions[currentPlayer] = moveTo[playerPositions[currentPlayer]];
            }
            
            else if (extraRoll[playerPositions[currentPlayer]] == 1)
            {
                increment = false;
            }
            
            else if (extraRoll[playerPositions[currentPlayer]] == -1)
            {
                skippingTurn[currentPlayer] = true;
            }
            
            if (playerPositions[currentPlayer] == 100)
            {
                ++posInRolls;
                return currentPlayer + 1;
            }
        }
        
        if (increment)
            currentPlayer = (currentPlayer + 1) % numberOfPlayers;
        
        ++posInRolls;
    }
}

int main()
{
    // Extra roll is 1 is again, 0 is nothing, -1 is skip turn
    
    int numberOfRolls(0);
    
    // I feel terrible for writing this
    while (scanf("%d", &rolls[numberOfRolls]), rolls[numberOfRolls++]);
    
    int numberOfPlayers;
    
    while (scanf("%d", &numberOfPlayers), numberOfPlayers)
    {
        for (int i = 0; i < 101; ++i)
        {
            moveTo[i] = -1;
            extraRoll[i] = 0;
        }
        
        int start, end;
        while (scanf("%d %d", &start, &end), start)
        {
            moveTo[start] = end;        
        }
        
        while (scanf("%d", &start), start)
        {
            
            if (start > 0)
                extraRoll[start] = 1;
            else
                extraRoll[start * - 1] = -1;
        }
        
        printf("%d\n", RunGame(numberOfPlayers));
        
    }
}