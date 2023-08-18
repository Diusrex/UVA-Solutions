#include <iostream>

using namespace std;

string rows[5];

int main() {
  int N;
  cin >>N;
  cin >> rows[0] >> rows[1] >> rows[2] >> rows[3] >> rows[4];

  for (int i = 0; i < N; ++i) {
    if (rows[1][i * 4 + 1] == '*') {
      cout << '1';
    } else if (rows[3][i * 4] == '*') {
      cout << '2';
    } else {
      cout << '3';
    }
  }
  cout << '\n';

}
