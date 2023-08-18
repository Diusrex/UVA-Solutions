#include <iostream>
#include <memory>

using namespace std;

const int MAX = 1000000;

int main() {
    bool prime[MAX + 1] = {0};
    for (int i = 3; i < MAX; i += 2) {
        prime[i] = true;
    }
    prime[2] = true;

    prime[1] = false;
    for (int i = 3; i < MAX; i += 2) {
        if (!prime[i]) {
            continue;
        }
        if (i * i > MAX) break;
        for (int j = i * i; j < MAX; j += 2 * i) {
            prime[j] = false;
        }
    }

    int num;
    while (cin >> num) {
        if (!prime[num]) {
            cout << num << " is not prime.\n";
            continue;
        }

        int reversed = 0;
        int temp = num;

        while (temp) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        if (prime[reversed] && num != reversed) {
            cout << num << " is emirp.\n";
        } else {
            cout << num << " is prime.\n";
        }
    }
}