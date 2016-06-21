#include <iostream>

using namespace std;

int main()
{
    unsigned long long num;
    
    while (cin >> num)
    {
        num = num / 2 + 1;
        num = num * num;
        
        cout << 6 * num - 9 << '\n';
    }
}