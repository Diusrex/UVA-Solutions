#include <iostream>

using namespace std;

int main()
{
    int m, n, larger, smaller;
    
    while (cin >> m >> n)
    {
        larger = max(m, n);
        smaller = min(m, n);
        cout << (larger - 1) * smaller + smaller - 1 << '\n';
    }
}