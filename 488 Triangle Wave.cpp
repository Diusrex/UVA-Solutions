#include <iostream>
#include <string>

using namespace std;

string amps[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};

int main()
{
    int T;

    cin >> T;

    while (T--)
    {
        int amp, freq;

        cin >> amp >> freq;

        while (freq--)
        {
            int i;
            for (i = 1; i < amp; ++i)
                cout << amps[i] << '\n';

            for (; i; --i)
                cout << amps[i] << '\n';

            if (freq)
                cout << '\n';
        }

        if (T)
            cout << '\n';
    }

}
