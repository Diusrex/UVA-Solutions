#include <iostream>

using namespace std;

// low card is removed first!
int Calc(int high, int low, int skip, const int numCards, bool removeLow) {
    if (high == low) {
        return low;
    }
    bool oddNumCards = numCards % 2 == 1;
    if (removeLow) {
        low += skip / 2;
    }
    int nextNumCards = numCards / 2;
    
    if (oddNumCards && !removeLow) {
        ++nextNumCards;
    }
    
    // If odd + remove low, then remove high.
    // If even + keep low, then remove high.
    bool removeHighCard = oddNumCards == removeLow;
    
    if (removeHighCard) {
        high -= skip / 2;
    }
    
    // Will be removing the low card iff we didn't remove the high card
    return Calc(high, low, skip * 2, nextNumCards, !removeHighCard);
}


int main() {
    int n;
    while (cin >> n, n) {
        cout << Calc(n, 1, 2, n, true) << '\n';
    }
}