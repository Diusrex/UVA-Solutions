#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int n;
        cin >> n;
        
        long long num = abs((((n * 63 + 7492) * 235) / 47 - 498) / 10);
        
        if (num < 0)
            num *= -1;
            
        cout << num % 10 << '\n';
    }

}