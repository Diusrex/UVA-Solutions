#include <iostream>
#include <cmath>

using namespace std;

// Find any easy groups
    // Ones where no conflicts

int N;

// [1, N]
int saysCorrect[25], saysWrong[25];

int GetNumBits(int i)
{
    int count = 0;
    while (i)
    {
        if (i & 1)
            ++count;
        i >>= 1;
    }
    return count;
}

int main()
{
    int a;
    while (cin >> N >> a, N)
    {
        for (int i = 0; i < N; ++i)
            saysCorrect[i] = saysWrong[i] = 0;
        
        while (a--)
        {
            int x, y;
            cin >> x >> y;
            --x;
            
            if (y > 0)
                saysCorrect[x] |= (1 << y - 1);
            else
                saysWrong[x] |= (1 << -y - 1);
        }
        
        const int Highest = (1 << N) - 1;
        int maxPositive = 0;
        for (int i = 1; i <= Highest; ++i)
        {
            int off = (~i) & Highest;
            int numBits = GetNumBits(i);
            if (numBits < maxPositive)
                continue;
            
            bool possible = true;
            
            for (int j = 0; j < N; ++j)
            {
                if ((i & (1 << j))
                    && ((off & saysWrong[j]) != saysWrong[j] || (i & saysCorrect[j]) != saysCorrect[j]))
                {
                    possible = false;
                    break;
                }
            }
            
            if (possible)
            {
                maxPositive = max(maxPositive, GetNumBits(i));
            }
        }
        
        cout << maxPositive << '\n';
    }
}