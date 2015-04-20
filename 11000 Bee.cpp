#include <iostream>

using namespace std;

const int MAX_REQUEST = 44;

unsigned int male[MAX_REQUEST + 1], total[MAX_REQUEST + 1];


int main()
{
    total[0] = 1;
    male[0] = 0;
    
    for (int i = 1; i <= MAX_REQUEST; ++i)
    {
        male[i] = total[i - 1];
        total[i] = male[i] + male[i - 1] + 1;
    }
    
    int n;
    
    while (cin >> n, n != -1)
        cout << male[n] << ' ' << total[n] << '\n';
}