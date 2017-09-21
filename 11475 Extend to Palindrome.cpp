#include <iostream>

using namespace std;

const int MaxC = 200010;
int wordSize;
string orig;
char word[MaxC];
// Ensure is > 2 * MaxN.
int P[MaxC];

void CalculateForAll() {
    // Originally from https://www.hackerrank.com/topics/manachers-algorithm
    int C = 0, R = -1;
    for (int i = 0; i < wordSize; ++i) {
        int rad = 0;
        // Can skip over everything covered by R - is identical to
        // mirrored position of i w.r.t C (pos 2C - i)
        if (i < R) {
            rad = min(P[2 * C - i], R - i);
        }
        
        // Try to extend.
        while (i + rad < wordSize && i - rad >= 0
               && word[i - rad] == word[i + rad]) {
            rad++;
        }
        --rad;
        P[i] = rad;
        
        if (i + rad > R) {
            C = i;
            R = i + rad;
        }
    }
}

bool LoadWord() {
    if (!(cin >> orig))
        return false;
    wordSize = orig.size() * 2 + 1;
    
    for (int i = 0; i < orig.size(); ++i) {
        word[i * 2 + 1] = orig[i];
    }
    return true;
}

int main() {
    for (int i = 0; i < MaxC; i += 2) {
        word[i] = '#'; // Some value that isn't in original string.
    }
    
    while (LoadWord()) {
        CalculateForAll();
        size_t minAdded = orig.size();
        // Center is a character
        for (int i = 0; i < wordSize; ++i) {
            int len = P[i] / 2 + i % 2;
            int characterSpot = i / 2;
            
            // Needs to have reached the end to be helpful
            // At worst, will be last character.
            if (characterSpot + len == orig.size()) {
                // P[i] is number of characters in orig in the palindrome.
                minAdded = min(minAdded, orig.size() - P[i]);
            }
        }
        
        cout << orig;
        for (int i = minAdded - 1; i >= 0; --i)
            cout << orig[i];
        
        cout << '\n';
    }
}