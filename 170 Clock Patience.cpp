#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pile
{
    Pile()
        : card(4),
        suit(4)
    {}
    
    vector<char> card;
    vector<char> suit;
    int pos;
};

int main()
{
    int cardPos[128];
    cardPos['A'] = 0; cardPos['2'] = 1; cardPos['3'] = 2;
    cardPos['4'] = 3; cardPos['5'] = 4; cardPos['6'] = 5;
    cardPos['7'] = 6; cardPos['8'] = 7; cardPos['9'] = 8;
    cardPos['T'] = 9; cardPos['J'] = 10; cardPos['Q'] = 11;
    cardPos['K'] = 12;
    
    vector<Pile> allPiles(13);
    
    char card, suit;
    while (cin >> card >> suit, card != '#')
    {
        allPiles[12].card[0] = card;
        allPiles[12].suit[0] = suit;
        
        int loadCount = 0;
        
        for (int cPos = 0; cPos < 4; ++cPos)
        {
            int pile = (cPos) ? 12 : 11;
                
            for (; pile >= 0; --pile)
            {
                cin >> card >> suit;
                allPiles[pile].card[cPos] = card;
                allPiles[pile].suit[cPos] = suit;
                ++loadCount;
                
            }
            
        }
        
        for (int i = 0; i < 13; ++i)
            allPiles[i].pos = 0;
        
        int pile = 12;
        int previous;
        
        int count = 0;
        
        while (allPiles[pile].pos < 4)
        {
            ++count;
            previous = pile;
            pile = cardPos[static_cast<int>(allPiles[pile].card[allPiles[pile].pos++])];
        }
        
        int pos = allPiles[previous].pos - 1;
        Pile & printedPile = allPiles[previous];
        if (count < 10)
            cout << '0' << count << ',' << printedPile.card[pos] << printedPile.suit[pos] << '\n';
        else
            cout << count << ',' << printedPile.card[pos] << printedPile.suit[pos] << '\n';
    }
}


