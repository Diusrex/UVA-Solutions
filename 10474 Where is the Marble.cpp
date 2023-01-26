#include <bits/stdc++.h>

using namespace std;

int numbers[10005];

int main()
{    
    int T = 1;
    int N, Q;
    
    while (cin >> N >> Q, N || Q)
    {
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        sort(numbers, numbers + N);
        
        cout << "CASE# " << T++ << ":\n";
        while (Q--)
        {
            int n;
            cin >> n;
            
            auto iter = lower_bound(numbers, numbers + N, n);
            if (iter == numbers + N || *iter != n)
                cout << n << " not found\n";
            else
                cout << n << " found at " << (iter - numbers) + 1 << '\n';
        }
    }
}
