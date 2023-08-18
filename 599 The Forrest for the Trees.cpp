#include <iostream>
#include <vector>

using namespace std;

bool valid[26];
vector<int> children[26];
vector<int> parents[26];
bool visited[26];


int VisitCount(int i) {
    if (visited[i]) {
        return 0;
    }
    visited[i] = true;

    int count = 1;
    for (int c : children[i]) {
        count += VisitCount(c);
    }
    for (int p : parents[i]) {
        count += VisitCount(p);
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 26; ++i) {
            valid[i] = visited[i] = false;
            children[i].clear();
            parents[i].clear();
        }
        
        string in;
        while (cin >> in, in[0] != '*') {
            int p = in[1] - 'A', c = in[3] - 'A';
            parents[c].push_back(p);
            children[p].push_back(c);
        }

        cin >> in;
        for (int i = 0; i < in.size(); i += 2) {
            valid[in[i] - 'A'] = true;
        }

        int trees = 0, acorns = 0;
        for (int i = 0; i < 26; ++i) {
            if (valid[i]) {
                int v = VisitCount(i);
                if (v == 1) {
                    ++acorns;
                } else if (v > 1) {
                    ++trees;
                }
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
    }
}