#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Exclusive
const int MaxIndex = 10000;

int digits[MaxIndex + 5][10];

void GenerateData()
{
    for (int i = 1; i < MaxIndex; ++i)
    {
        for (int j = 0; j < 10; ++j)
            digits[i][j] = digits[i - 1][j];
        
        int temp = i;
        while (temp)
        {
            digits[i][temp % 10]++;
            temp /= 10;
        }
    }
}

int main()
{
    GenerateData();
    
    int T;
    cin >> T;
    
    while (T--)
    {
        int pos;
        cin >> pos;
        
        cout << digits[pos][0];
        for (int i = 1; i < 10; ++i)
            cout << ' ' << digits[pos][i];
        
        cout << '\n';
    }
}