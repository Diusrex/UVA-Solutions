#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int first = 0, second;
        char junk, letter;

        for (int i = 0; i < 3; ++i)
        {
            cin >> letter;
            first = first * 26 + letter - 'A';
        }
        cin >> junk >> second;

        if (abs(first - second) <= 100)
            cout << "nice\n";
        else
            cout << "not nice\n";
    }
}
