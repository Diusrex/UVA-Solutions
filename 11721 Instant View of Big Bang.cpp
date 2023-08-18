#include <iostream>
#include <vector>

using namespace std;

const int Ignored = -2000000000;

int N;
// [from][to]
vector<pair<int, int>> connections[1005];
int visitedVal[1005];
bool negCycle[1005];

bool HasNegativeCycle(int n, int v) {
    // Decreased from previous visit, so we have a negative cycle.
    if (v < visitedVal[n]) {
        negCycle[n] = true;
        return true;
    } else if (negCycle[n]) {
        return true;
    } else if (visitedVal[n] != Ignored) {
        // This direction doesn't have a cycle.
        return false;
    } 
    
    visitedVal[n] = v;
    for (const auto c : connections[n]) {
        if (HasNegativeCycle(c.first, v + c.second)) {
            return negCycle[n] = true;
        }
    }

    visitedVal[n] = Ignored;
    return negCycle[n];
}


int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            visitedVal[i] = Ignored;
            negCycle[i] = false;
            for (int j = 0; j < N; ++j) {
                connections[i].clear();
            }
        }

        for (int i = 0; i < M; ++i) {
            int from, to, val;
            cin >> from >> to >> val;
            connections[from].push_back({to, val});
        }
        
        bool possible = false;
        cout << "Case " << t << ":";
        for (int i = 0; i < N; ++i) {
            if (HasNegativeCycle(i, 0)) {
                cout << ' ' << i;
                possible = true;
            }
        }
        
        if (!possible) {
            cout << " impossible";
        }
        cout << '\n';
    }
}