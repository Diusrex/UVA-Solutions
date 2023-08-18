#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Cube {
    int l, s, h;

    bool operator<(const Cube& other) {
        if (other.l != l) {
            return l > other.l;
        }
        if (other.s != s) {
            return s > other.s;
        }
        return h > other.h;
    }
};

// [Current][previous]
int best[100][100] = {};

int Calculate(int c, int prev, const vector<Cube>& cubes) {
    if (c == cubes.size()) {
        return 0;
    }
    if (best[c][prev] != -1) {
        return best[c][prev];
    }

    // Always valid to skip.
    int current = Calculate(c + 1, prev, cubes);
    if (cubes[c].l < cubes[prev].l && cubes[c].s < cubes[prev].s) {
        current = max(current, cubes[c].h + Calculate(c + 1, c, cubes));
    }

    return best[c][prev] = current;
}

int main() {
    int N, T = 0;
    while (cin >> N && N) {
        std::vector<Cube> cubes;

        cubes.reserve(N * 3);

        int largest = 0;

        for (int i = 0; i < N; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            cubes.push_back({max(a, b), min(a, b), c});
            cubes.push_back({max(a, c), min(a, c), b});
            cubes.push_back({max(b, c), min(b, c), a});
            largest = max(largest, max(a, max(b, c)));
        }

        cubes.push_back({largest + 1, largest + 1, 0});

        std::sort(cubes.begin(), cubes.end());

        for (int i = 0; i < cubes.size(); ++i) {
            for (int j = 0; j < cubes.size(); ++j) {
                best[i][j] = -1;
            }
        }

        std::cout << "Case " << ++T << ": maximum height = " << Calculate(0, 0, cubes) << '\n';
    }
}