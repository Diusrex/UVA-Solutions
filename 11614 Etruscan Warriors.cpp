#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        ull num;
        cin >> num;
        
        cout << ((int)sqrt(8*num + 1) - 1) / 2 << '\n';
    }
}
