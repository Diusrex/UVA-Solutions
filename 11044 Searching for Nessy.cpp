#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    int n, m;
    while (T--)
    {
        cin >> n >> m;
        
        n -= 2; m -=2;
        cout << (n / 3 + ((n % 3 != 0) ? 1 : 0)) * (m / 3 + ((m % 3 != 0) ? 1 : 0)) << '\n';
    
    }

}