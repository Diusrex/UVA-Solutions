#include <iostream>

using namespace std;

long long count[51];

int main()
{
    // Calculating
    count[1] = 1;
    count[2] = 2;
    
    for (int i = 3; i <= 50; ++i)
        count[i] = count[i - 1] + count[i -2];
    
    
    
    int n;
    while (cin >> n, n)
        cout << count[n] << '\n';
}