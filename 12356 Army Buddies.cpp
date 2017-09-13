#include <iostream>
#include <utility>

using namespace std;

int toLeft[100000];
int toRight[100000];

const int End = -1;

pair<int, int> Update(int firstDead, int lastDead) {
    int leftMost = toLeft[firstDead];
    int rightMost = toRight[lastDead];
    
    if (leftMost != End) {
        toRight[leftMost] = rightMost;
    }
    if (rightMost != End) {
        toLeft[rightMost] = leftMost;
    }
    
    return make_pair(leftMost, rightMost);
}

int main() {
    int N, B;
    while (cin >> N >> B, N) {
        for (int i = 0; i < N; ++i) {
            toLeft[i] = i - 1;
            toRight[i] = i + 1;
        }
        toLeft[0] = toRight[N - 1] = End;
        
        while (B--) {
            int l, r;
            cin >> l >> r;
            // Want 0 indexed
            --l; --r;
            
            pair<int, int> new_ends = Update(l, r);
            if (new_ends.first == End) cout << "* ";
            else cout << (new_ends.first + 1) << " ";
            
            if (new_ends.second == End) cout << "*\n";
            else cout << (new_ends.second + 1) << "\n";
        }
        cout << "-\n";
    }
}