#include <iostream>

using namespace std;

string rows[65];

char ch_orientation[] = {'E', 'S', 'W', 'N'};
int r_orientation[] = {0, 1, 0, -1};
int c_orientation[] = {1, 0, -1, 0};

bool Valid(int i, int I) {
    return i >= 0 && i < I;
}

int main() {
    int T;
    cin >> T;
    string sep = "";
    while (T--) {
        int R, C;
        cin >> R >> C;
        string line;
        getline(cin, line);
        for (int i = 0; i < R; ++i) {
            getline(cin, rows[i]);
        }
        int r, c;
        cin >> r >> c;
        --r;
        --c;

        // North.
        int o = 3;

        char command;
        while (cin >> command && command != 'Q') {
            if (command == 'R') {
                o = (o + 1) % 4;
            } else if (command == 'L') {
                o = (o + 3) % 4;
            } else if (command == 'F') {
                int new_r = r + r_orientation[o];
                int new_c = c + c_orientation[o];

                if (Valid(new_r, R) && Valid(new_c, C) && rows[new_r][new_c] == ' ') {
                    r = new_r;
                    c = new_c;
                }
            }
        }

        cout << sep << (r + 1) << ' ' << (c + 1) << ' ' << ch_orientation[o] << '\n';
        sep = "\n";
    }
}