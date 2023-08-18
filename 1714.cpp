#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
// Purposefully don't do a full max, since that could overflow....
int MAX = 2147480000;
// Has a '*' appended to the end for the final return.
string requested;

int R, C;
// [r][c]
string grid[51];
bool seen[50005][51][51];

struct Spot{
  int spot, r, c;
};

bool RValid(int r) {
  return r >= 0 && r < R;
}

bool CValid(int c) {
  return c >= 0 && c < C;
}

int rChanges[] = {-1, 1, 0, 0};
int cChanges[] = {0, 0, -1, 1};

void Move(int& r, int& c,  int index) {
  char start = grid[r][c];
  while (RValid(r) && CValid(c) && grid[r][c] == start) {
    r += rChanges[index];
    c += cChanges[index];
  }
  // It's fine if it gets pushed out of the grid.
}

int BFS() {
  std::queue<Spot> current;
  current.push(Spot{0, 0, 0});
  std::queue<Spot> next;
  int count = 0;
  while (true) {
    count += 1;

    while (!current.empty()) {
      Spot cur = current.front();
      current.pop();
      if (grid[cur.r][cur.c] == requested[cur.spot]) {
        int spot = cur.spot + 1;
        if (spot == requested.size()) {
          return count;
        }

        if (!seen[spot][cur.r][cur.c]) {
          seen[spot][cur.r][cur.c] = true;
          next.push(Spot{spot, cur.r, cur.c});
        }
      } else {
        for (int i = 0; i < 4; ++ i) {
          int r = cur.r;
          int c = cur.c;
          Move(r, c, i);
          if (RValid(r) && CValid(c) && !seen[cur.spot][r][c]) {
            seen[cur.spot][r][c] = true;
            next.push(Spot{cur.spot, r, c});
          }
        }
      }
    }

    current.swap(next);
  }
}



int main() {
  while (cin >> R >> C) {
    for (int r = 0; r < R; ++r) {
      cin >> grid[r];
    }
    cin >> requested;
    requested += "*";
    for (int i = 0; i < requested.size(); ++i) {
      std::memset(seen[i], false, sizeof(seen[i]));
    }

    cout << BFS() << '\n';
  }
}
