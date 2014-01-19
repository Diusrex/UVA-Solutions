#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // Are stored [num % 13][num / 13]
    string cardFirst[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    string cardSecond[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string temp;
    char separator[2];
    separator[0] = separator[1] = '\0';
    int shuffles[101][52], numShufflesKnown, numShufflesDone, orderOfShuffles[101], T, pos;
    
    
    scanf("%d", &T);
    
    while (T--)
    {
        printf("%s", separator);
        separator[0] = '\n';
        
        scanf("%d", &numShufflesKnown);
        
        for (int i = 0; i < numShufflesKnown; ++i)
        {
            for (int j = 0; j < 52; ++j)
            {
                scanf("%d", &shuffles[i][j]);
                --shuffles[i][j];
            }
        }
        
        cin.ignore();
        numShufflesDone = 0;
        getline(cin, temp);
        
        while (temp != "")
        {
            orderOfShuffles[numShufflesDone++] = atoi(temp.c_str()) - 1;
            getline(cin, temp);
        }
        
        
        for (int i = 0; i < 52; ++i)
        {
            pos = i;
            for (int c = numShufflesDone - 1; c >= 0; --c)
                pos = shuffles[orderOfShuffles[c]][pos];
            
            
            printf("%s of %s\n", cardFirst[pos % 13].c_str(), cardSecond[pos / 13].c_str());
        }
    }
}