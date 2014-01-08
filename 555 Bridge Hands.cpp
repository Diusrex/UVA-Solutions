#include <cstdio>
#include <map>

int main()
{
    std::map<char, int> cardConversion, suitConversion, playerConversion;
    playerConversion['S'] = 1;
    playerConversion['W'] = 2;
    playerConversion['N'] = 3;
    playerConversion['E'] = 0;
    
    cardConversion['2'] = suitConversion['C'] = 0;
    cardConversion['3'] = suitConversion['D'] = 1;
    cardConversion['4'] = suitConversion['S'] = 2;
    cardConversion['5'] = suitConversion['H'] = 3;
    cardConversion['6'] = 4;
    cardConversion['7'] = 5;
    cardConversion['8'] = 6;
    cardConversion['9'] = 7;
    cardConversion['T'] = 8;
    cardConversion['J'] = 9;
    cardConversion['Q'] = 10;
    cardConversion['K'] = 11;
    cardConversion['A'] = 12;
    
    char starter, cardSuit, cardValue, printout[4], cardOut[13], suitOut[4];
    printout[0] = 'S';
    printout[1] = 'W';
    printout[2] = 'N';
    printout[3] = 'E';
    
    cardOut[0] = '2';
    cardOut[1] = '3';
    cardOut[2] = '4';
    cardOut[3] = '5';
    cardOut[4] = '6';
    cardOut[5] = '7';
    cardOut[6] = '8';
    cardOut[7] = '9';
    cardOut[8] = 'T';
    cardOut[9] = 'J';
    cardOut[10] = 'Q';
    cardOut[11] = 'K';
    cardOut[12] = 'A';
    
    suitOut[0] = 'C';
    suitOut[1] = 'D';
    suitOut[2] = 'S';
    suitOut[3] = 'H';
    
    int current;
    
    // is [player][suit][card]
    bool hasCard[4][4][13];
    
    for (int i = 0; i < 4; ++i)
        for (int x = 0; x < 4; ++x)
            for (int y = 0; y < 13; ++y)
                hasCard[i][x][y] = false;
    
    while (scanf("%c", &starter), starter != '#')
    {
        current = playerConversion[starter];
        
        for (int i = 0; i < 52; ++i)
        {
            if (i % 26 == 0)
                scanf("%*c");
                
            scanf("%c%c", &cardSuit, &cardValue);
            
            hasCard[current][suitConversion[cardSuit]][cardConversion[cardValue]] = true;
            
            current = (current + 1) % 4;
            
            
        }
        
        scanf("%*c");
        for (int player = 0; player < 4; ++player)
        {
            printf("%c:", printout[player]);
            
            for (int suit = 0; suit < 4; ++suit)
                for (int card = 0; card < 13; ++card)
                {
                    if (hasCard[player][suit][card])
                    {
                        printf(" %c%c", suitOut[suit], cardOut[card]);
                        hasCard[player][suit][card] = false;
                    }
            }
            
            printf("\n");
        }
    }
}