#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// If equal to 0, then has not been set yet.
long long C[55][55];

long long Coefficent(int N, int K)
{
    // K will NEVER be 0.
    if (N == K || K == 0)
        return 1;
    
    long long & val = C[N][K];
    
    if (val == 0)
    {
        val = Coefficent(N - 1, K - 1) + Coefficent(N - 1, K);
    }
    
    return val;
}

int main()
{
    string input;
    int T;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> input;
        
        // Parse in the numbers:
        int pos = 1;
        for (; input[pos] != '+'; ++pos)
            ;
        
        string first = input.substr(1, pos - 1);
        int start = pos + 1;
        
        for (; input[pos] != ')'; ++pos)
            ;
        string second = input.substr(start, pos - start);
        
        int k = atoi(input.substr(pos + 2).c_str());
        
        cout << "Case " << t << ": " << first;
        
        // Special case
        if (k == 1)
        {
            cout << '+' << second << '\n';
            continue;
        }
        cout << '^' << k;
        
        
        for (int i = 1; i < k; ++i)
        {
            cout << '+' << Coefficent(k, k - i)
                 << '*'
                 << first; if (k - i != 1) cout << '^' << (k - i);
            cout << '*'
                 << second; if (i != 1) cout << '^' << i;
        }
        
        cout << '+' << second << '^' << k << '\n';
    }
    
}