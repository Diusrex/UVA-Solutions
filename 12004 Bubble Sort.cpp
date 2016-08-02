#include <iostream>

using namespace std;

const int NumValues = 1e5 + 5;

double values[NumValues];

int main()
{
    double increase = 0;
    for (int i = 1; i < NumValues; ++i, increase += 0.5)
    {
        values[i] = values[i - 1] + increase;
    }
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int num;
        cin >> num;
        cout << "Case " << t << ": ";
        if (values[num] == (unsigned long long)values[num])
            cout << (unsigned long long)values[num] << '\n';
        else
            cout << (unsigned long long)(values[num] * 2) << "/2\n";
    }
}