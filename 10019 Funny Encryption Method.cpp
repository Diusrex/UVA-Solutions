#include <iostream>

using namespace std;

int GetNumBits(int n)
{
    int count = 0;
    
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int asDec = GetNumBits(n);
        int asHex = 0;
        
        while (n)
        {
            asHex += GetNumBits(n % 10);
            n /= 10;
        }
        
        cout << asDec << ' ' << asHex << '\n';
    }
}