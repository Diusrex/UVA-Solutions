#include <iostream>
#include <algorithm>

using namespace std;

// Will start indexing at [1][1]
long long A[23][23];
int n;

long long GetA(int i, int j)
{
    long long &val = A[i][j];
    
    if (val == -1)
    {
        if (i < j)
        {
            for (int k = i; k < j; ++k)
                val = max(val, GetA(i, k) + GetA(k + 1, j));
        }
        
        else
        {
            long long s1 = 0;
            if (i < n)
            {
                for (int k = i + 1;k <= n; ++k)
                    s1 = max(s1, GetA(k, 1) + GetA(k, j));
            }
            
            long long s2 = 0;
            if (j > 1)
            {
                for (int k = 1; k < j; ++k)
                    s2 = max(s2, GetA(i, k) + GetA(n, k));
            }
            
            val = s1 + s2;
        }
        
        
    }
    
    return val;
}

int main()
{
    
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                A[i][j] = -1;
        
        cin >> A[n][1];
        
        cout << GetA(1, n) << '\n';
        
    }
}