#include <iostream>

using namespace std;

// Need the extra bit from unsiged, otherwise will overflow for highestSol.
typedef unsigned long long ull;

int main() {
    ull V;
    while (cin >> V, V) {
        // Round down
        ull highestSol = (V * 10) / 9;
        
        ull lowest = highestSol;
        for (; lowest - lowest / 10 == V; --lowest)
            ;
        // Value it gets to is invalid.
        ++lowest;
        
        // Not certain if it is possible for there to not be a solution.
        if (lowest <= highestSol) {
            cout << lowest;
            for (ull i = lowest + 1; i <= highestSol; ++i) {
                cout << " " << i;
            }
        }
        cout << "\n";
        
    }
}