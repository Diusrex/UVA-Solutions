#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int N;
bool tried[105][22];

int length[105];
char weapons[105][22];

// Note: A set/map would be faster, but is far more complex.

// Must completely match the current weapon substring or the other weapon.
//  (Or both!)
bool MatchPrefix(int weapon, int pos, int otherWeapon, int currentLen, int shortestLength) {
    char* shorter;
    char* longer;
    if (shortestLength == currentLen) {
        shorter = weapons[weapon] + pos;
        longer = weapons[otherWeapon];
    } else {
        shorter = weapons[otherWeapon];
        longer = weapons[weapon] + pos;
    }
    
    auto res = std::mismatch(shorter, shorter + shortestLength, longer);

    // shorter is a prefix of longer.
    return res.first == shorter + shortestLength;
}

// Is it possible to match with other words to reach the end
// Assumes haven't reached end of the string.
bool Solvable(int weapon, int pos) {
    if (!tried[weapon][pos]) {
        tried[weapon][pos] = true;
        int currentLen = length[weapon] - pos;
        
        // Note that we allow matching against itself as well, as long as we are not at the start.
        for (int i = 0; i < N; ++i) {
            if (pos == 0 && i == weapon)
                continue;
        
            int shortestLength = min(currentLen, length[i]);
            if (MatchPrefix(weapon, pos, i, currentLen, shortestLength)) {
                if (currentLen == length[i]) {
                    // They complete each other!
                    return true;
                } else if (currentLen == shortestLength) {
                    // We moved into the other weapon.
                    if (Solvable(i, shortestLength)) {
                        return true;
                    }
                } else {
                    // We advanced further into this weapon.
                    if (Solvable(weapon, pos + shortestLength)) {
                        return true;
                    }
                }
            }
        }
        
    }
    
    return false;
}

bool Solvable() {
    for (int i = 0; i < N; ++i) {
        if (Solvable(i, 0)) {
            return true;
        }
    }
    return false;
}

int main()
{
    char junk[25];
    
    int T = 1;
    while (scanf("%d", &N), N)
    {
        for (int i = 0 ; i < N; ++i) {
            scanf("%s %s", junk, weapons[i]);
            length[i] = std::strlen(weapons[i]);
            for (int j = 0; j < length[i]; ++j) {
                tried[i][j] = false;
            }
        }
        
        cout << "Case #" << T++ << ": ";
        if (Solvable()) {
            cout << "Ambiguous.\n";
        } else {
            cout << "Not ambiguous.\n";
        }
    }
}