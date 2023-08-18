#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Sol {
    int a, b, c;
};

int main() {
    int cubes[201];
    map<int, int> cube_to_num;
    for (int i = 2; i <= 200; ++i) {
        cubes[i] = i * i * i;
        cube_to_num[i * i * i] = i;
    }

    map<int, vector<Sol>> solutions;

    for (int a = 2; a < 200; ++a) {
        int a3 = a * a * a;
        for (int b = a; b < 200; ++b) {
            int b3 = b * b * b;
            for (int c = b; c < 200; ++c) {
                int sum = a3 + b3 + c * c * c;
                if (auto iter = cube_to_num.find(sum);
                    iter != cube_to_num.end()) {
                    solutions[iter->second].push_back({a, b, c});
                }
            }
        }
    }

    for (const auto& sol : solutions) {
        for (const auto& s : sol.second) {
            cout << "Cube = " << sol.first << ", Triple = (" << s.a << ',' << s.b << ',' << s.c << ")\n";
        }
    }
}