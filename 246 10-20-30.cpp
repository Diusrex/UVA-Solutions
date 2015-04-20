#include <iostream>
#include <queue>
#include <set>

using namespace std;

const int NumPiles = 7;
// For draw, keep two ints:
    // Last time state changed card play, card that was played right after change

// Start and end are inclusive
struct Pile
{    
    void Reset()
    {
        start = 0;
        end = -1;
        playable = true;
    }
    
    void AddCard(int card)
    {
        ++end;
        pile[end] = card;
    }
    
    void RemoveCards(queue<int> &deck)
    {
        for (;;)
        {
            int first, second, third;
            if (start > end)
            {
                playable = false;
                break;
            }
            // Not enough cards
            else if (end - start + 1 < 3)
                break;
            else if ((pile[start] + pile[start + 1] + pile[end]) % 10 == 0)
            {
                first = start;
                second = start + 1;
                third = end;
                
                start += 2;
                --end;
            }
            
            else if ((pile[start] + pile[end - 1] + pile[end]) % 10 == 0)
            {
                first = start;
                second = end - 1;
                third = end;
                
                ++start;
                end -= 2;
            }
            
            else if ((pile[end - 2] + pile[end - 1] + pile[end]) % 10 == 0)
            {
                first = end - 2;
                second = end - 1;
                third = end;
                
                end -= 3;
            }
            
            else
                break;
            
            deck.push(pile[first]);
            deck.push(pile[second]);
            deck.push(pile[third]);
        }
    }
        
    int start, end;
    bool playable;
    
    int pile[100000];
};

Pile piles[NumPiles];

bool SomePilesPlayable()
{
    for (int i = 0; i < NumPiles; ++i)
        if (piles[i].playable)
            return true;
        
    return false;
}

string GetState(queue<int> deck)
{
    string val(59, ',');
    string::iterator iter = val.begin();
    
    for (int i = 0; i < NumPiles; ++i, ++iter)
    {
        for (int c = piles[i].start; c <= piles[i].end; ++c, ++iter)
        {
            *iter = piles[i].pile[c] + '0';
        }
    }
    
    while (!deck.empty())
    {
        int current = deck.front();
        deck.pop();
        *iter = current + '0';
        ++iter;
    }
    
    return val;
}

bool IsNewState(set<string> &allVisitedStates, const queue<int> &deck)
{
    string state = GetState(deck);
    if (allVisitedStates.find(state) != allVisitedStates.end())
        return false;
    
    allVisitedStates.insert(state);
}

int main()
{
    int card;
    
    while (cin >> card, card)
    {
        set<string> allVisitedStates;
        for (int i = 0; i < NumPiles; ++i)
            piles[i].Reset();
        
        
        queue<int> deck;
        deck.push(card % 10);
        for (int i = 1; i < 52; ++i)
        {
            cin >> card;
            deck.push(card % 10);
        }
        
        int numCardsPlayed = 0;
        int currentPile = 0;
        
        while (!deck.empty() && SomePilesPlayable() && IsNewState(allVisitedStates, deck))
        {
            for (; !piles[currentPile].playable; currentPile = (currentPile + 1) % NumPiles)
                ;
            
            int card = deck.front();
            deck.pop();
            
            piles[currentPile].AddCard(card);
            piles[currentPile].RemoveCards(deck);
            
            currentPile = (currentPile + 1) % NumPiles;
            ++numCardsPlayed;
        }
        
        if (deck.empty())
            cout << "Loss: " << numCardsPlayed << '\n';
        else if (!SomePilesPlayable())
            cout << "Win : " << numCardsPlayed << '\n';
        else
            cout << "Draw: " << numCardsPlayed << '\n';
    }
}