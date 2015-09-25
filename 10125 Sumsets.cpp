#include <iostream>
#include <algorithm>

using namespace std;

int S[1001];

int GetBestIndex(int N)
{
    for (int d = N - 1; d >= 0; --d)
    {
        for (int c = 0; c < N; ++c)
        {
            if (c == d)
                continue;
            
            int a = 0, b = N - 1;
            while (a == c || a == d)
                ++a;
            while (b == c || b == d)
                --b;
            
            while (a < b)
            {
                int diff = S[d] - (S[a] + S[b] + S[c]);
                if (diff == 0)
                {
                    return d;
                }
                
                else if (diff > 0)
                {
                    ++a;
                    while (a == c || a == d)
                        ++a;
                }
                else
                {
                    --b;
                    while (b == c || b == d)
                        --b;
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    int N;
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> S[i];
        
        sort(S, S + N);
        
        int index = GetBestIndex(N);
        
        if (index == -1)
            cout << "no solution\n";
        else
            cout << S[index] << '\n';
    }
}