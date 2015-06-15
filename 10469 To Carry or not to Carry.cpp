#include <iostream>

using namespace std;

int main()
{
    int i, j;
    while (cin >> i >> j)
        cout << (i ^ j) << '\n';
}