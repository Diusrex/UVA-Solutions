#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, D, R;
    while (cin >> N >> D >> R, N) {
        vector<int> morning;
        for (int i = 0; i < N; ++i) {
            int d;
            cin >> d;
            morning.push_back(d);
        }
        sort(morning.begin(), morning.end());

        vector<int> afternoon;
        for (int i = 0; i < N; ++i) {
            int d;
            cin >> d;
            afternoon.push_back(d);
        }
        sort(afternoon.begin(), afternoon.end(), std::greater<int>());

        int overtime = 0;
        for (int i = 0; i < N; ++i) {
            overtime += max(0, morning[i] + afternoon[i] - D);
        }
        cout << overtime * R << '\n';
    }
}