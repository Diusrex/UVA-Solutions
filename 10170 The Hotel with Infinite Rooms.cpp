#include <iostream>

using namespace std;

// Starting: 2
// Day 

// N * (N + 1) / 2 - (start) * (start - 1) / 2 = sum
// N * (N + 1) = 2 * sum + start * (start - 1)
// N^2 + 2N + 1 = ...


long long Sum(long long N) {
    return N * (N + 1) / 2;
}

int main() {
    long long S, D;
    while (cin >> S >> D) {
        long long lower = 1, upper = D;

        D += Sum(S);

        cout << "Actually want " << D << '\n';


        while (lower < upper) {
            long long mid = (lower + upper) / 2;
            cout << lower << ' ' << upper << ' ' << mid << " with sum " << Sum(mid) << '\n';
            if (Sum(mid) > D) {
                upper = mid;
            } else if (Sum(mid) < D) {
                lower = mid + 1;
            } else {
                lower = upper = mid;
            }
        }

        cout << lower << '\n';
    }
}