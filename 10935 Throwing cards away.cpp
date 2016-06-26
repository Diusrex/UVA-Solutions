#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> deck;
    int n;
    while (cin >> n, n)
    {
        for (int i = 1; i <= n; ++i)
            deck.push(i);
        cout << "Discarded cards:";
        
        string sep = " ";
        while (deck.size() > 1)
        {
            cout << sep << deck.front();
            sep = ", ";
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }
        
        cout << "\nRemaining card: " << deck.front() << '\n';;
        deck.pop();
    }
    
}