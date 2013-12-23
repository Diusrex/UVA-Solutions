#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        
        cout << (2 * x - y) * z / (x+ y ) << '\n';
    }
}