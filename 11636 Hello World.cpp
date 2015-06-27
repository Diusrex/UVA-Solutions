#include <iostream>

using namespace std;

int main()
{
    int n, T = 1;
    
    while (cin >> n, n > 0)
    {
        int num = 1, count = 0;
        
        while (num < n)
        {
            num <<= 1;
            ++count;
        }
        
        cout << "Case " << T++ << ": " << count << '\n';
    }
}