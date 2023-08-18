#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M, K;
        cin >> N >> M >> K;

        int last_seen[K + 1];
        for (int i = 0; i <= K; ++i)
            last_seen[i] = -1;
        // {-position, num}
        priority_queue<pair<int, int>> first_limiter;

        int shortest = N + 1;

        // Special case the initial elements.
        // last_seen.insert({1, 0});
        // first_limiter.push({0, 1});
        // first_limiter.push({-1, 2});
        // first_limiter.push({-2, 3});

        int prev = 1, two_prev = 0, three_prev = 0;

        // Once this is valid then we have seen all required numbers.
        int num_seen = 0;

        for (int n = 0; n < N; ++n) {
            int cur;
            if (n < 3) {
                cur = n + 1;
            } else {
                cur = (prev + two_prev + three_prev) % M + 1;
            }

            three_prev = two_prev;
            two_prev = prev;
            prev = cur;

            if (cur > K) {
                continue;
            }

            if (last_seen[cur] == -1) {
                ++num_seen;
                first_limiter.push({-n, cur});
            }
            last_seen[cur] = n;

            if (num_seen == K) {
                // While there was a more recent version of the limiter.
                while (last_seen[first_limiter.top().second] != -first_limiter.top().first) {
                    auto c = first_limiter.top();
                    first_limiter.pop();

                    first_limiter.push({-last_seen[c.second], c.second});
                }
                if (n - -first_limiter.top().first + 1 < shortest) {
                    shortest = n - -first_limiter.top().first + 1;
                }
            }
        }

        cout << "Case " << (t + 1) << ": ";
        if (shortest > N) {
            cout << "sequence nai\n";
        } else {
            cout << shortest << '\n';
        }
    }
}