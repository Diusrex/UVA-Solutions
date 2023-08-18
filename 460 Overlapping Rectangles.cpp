#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    string sep = "";

    while (T--) {
        // x1, y1, x2, y2.
        int b1[4];
        cin >> b1[0] >> b1[1] >> b1[2] >> b1[3];

        int b2[4];
        cin >> b2[0] >> b2[1] >> b2[2] >> b2[3];

        // Max of their lower points, min of their higher - would they form a box between lower & higher?
        int x_low = max(b1[0], b2[0]), x_high = min(b1[2], b2[2]);
        int y_low = max(b1[1], b2[1]), y_high = min(b1[3], b2[3]);

        if (x_low < x_high && y_low < y_high) {
            cout << sep << x_low << ' ' << y_low << ' ' << x_high << ' ' << y_high << '\n';
        } else {
            cout << sep << "No Overlap\n";
        }
        sep = "\n";
    }
}