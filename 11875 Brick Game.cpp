#include <iostream>

using namespace  std;

int main()
{
    int T;
    cin >> T;
    int n, c;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> c;
            if (i == n / 2)
                cout << "Case " << t << ": " << c << '\n';
        }
    }
}