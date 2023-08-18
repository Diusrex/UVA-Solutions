#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int offset = 10000;
const int M = 20005;
int num_at_spot[M];
int positions[M][1000];

bool Possible(int i, int middle_sum) {
  for (int start = 0, end = num_at_spot[i] - 1; start <= end; ++start, --end) {
    if (positions[i][start] + positions[i][end] != middle_sum) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(num_at_spot, 0, sizeof(num_at_spot));

    int N;
    cin >> N;
    while (N--) {
      int x, y;
      cin >> x >> y;
      y += offset;
      int& spot = num_at_spot[y];
      positions[y][spot++] = x;
    }

    bool seen = false;
    bool possible = true;

    // This is NOT divided by two to calculate the true middle to avoid FP operations)
    int middle_sum;

    for (int i = 0; i < M && possible; ++i) {
      sort(positions[i], positions[i] + num_at_spot[i]);
      if (num_at_spot[i]) {
        if (!seen) {
          // This is correct even if it has an even or odd number of elements
          middle_sum = positions[i][0] + positions[i][num_at_spot[i]-1];
          seen = true;
        }

        possible = Possible(i, middle_sum);
      }
    }
    cout << (possible ? "YES\n" : "NO\n");
  }
}

