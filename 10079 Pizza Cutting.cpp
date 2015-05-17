#include <iostream>

using namespace std;

int main()
{
    long long num;
    
    while (cin >> num, num >= 0)
        cout << ((num * (num + 1)) / 2 + 1) << '\n';
}