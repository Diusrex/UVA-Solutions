#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// If indicies r + c is even, is N, otherwise M.

// Index into N or M is (r * perRow + c)

// Can only add edges between required elements!

const int MaxN = 400, MaxM = 400;
int N, M;
vector<int> a[MaxN], b[MaxN];
int matched[MaxN], mark[MaxM], mate[MaxM];

int dfs(int v) {
    if (v < 0) return 1;
    for (int to : a[v]) {
        if (!mark[to]++ && dfs(mate[to]))
            return matched[mate[to] = v] = 1;
    }
    return 0;
}

int set_mark() {
    memset(matched, 0, sizeof matched);
    memset(mate, -1, sizeof mate);
    memset(mark, 0, sizeof mark);
    for (int i = 0; i < N; ++i) {
        for (int to : a[i]) {
            if (mate[to] < 0) {
                matched[mate[to] = i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        if (!matched[i] && dfs(i)) memset(mark, 0, sizeof mark);
    for (int i = 0; i < N; ++i)
        if (!matched[i]) dfs(i);
}

int edge_cover_count() {
    set_mark();
    int count = 0;
    for (int i = 0; i < M; ++i) {
        if (mate[i] >= 0 || b[i].size()) {
            ++count;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!matched[i] && a[i].size()) {
            ++count;
        }
    }
    return count;
}

// [r][c]
bool included[40][10];

// Must be updated every iteration
int NperRow;
int MperRow;

int GetIndex(int r, int c) {
    bool isN = (r + c) % 2 == 0;
    return r * (isN ? NperRow : MperRow) + c / 2;
}

const vector<pair<int, int>> changes = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> R >> C;
        
        NperRow = C / 2 + 1;
        MperRow = C / 2 + 1;
        
        N = NperRow * R;
        M = MperRow * R;
        
        for (int i = 0; i < N; ++i)
            a[i].clear();
        for (int i = 0; i < M; ++i)
            b[i].clear();
        
        string line;
        for (int r = 0; r < R; ++r) {
            cin >> line;
            for (int c = 0; c < C; ++c) {
                included[r][c] = (line[c] == '*');
            }
        }
        
        int count = 0;
        // Update edges for each node
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (!included[r][c])
                    continue;
                
                bool isN = (r + c) % 2 == 0;
                int index = GetIndex(r, c);
                vector<int>* current =
                    (isN ? a + index : b + index);
                
                int beside = 0;
                for (const auto& change : changes) {
                    int newR = r + change.first;
                    int newC = c + change.second;
                    
                    if (newR >= 0 && newR < R && newC >= 0 && newC < C
                        && included[newR][newC]) {
                        current->push_back(GetIndex(newR, newC));
                        ++beside;
                    }
                }
                if (beside == 0)
                    ++count;
            }
        }
        
        count += edge_cover_count();
        cout << count << '\n';
    }
}