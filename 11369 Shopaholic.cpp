#include <iostream>
#include <algorithm>

using namespace std;

int items[20001];

bool mycomp(int i, int j)
{
    return i > j;
}

int main()
{
    int T, n;
    cin >> T;
    
    long long total;
    
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> items[i];
        
        sort(items, items + n, mycomp);
        
        total = 0;
        for (int i = 2; i < n; i += 3)
            total += items[i];
        
        cout << total << '\n';
    }
}