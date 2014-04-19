#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, B;
    
    while (scanf("%d%d", &N, &B), N)
    {
        vector<int> balls(B);
        vector<bool> able(N + 1, false);
        
        for (int i = 0; i < B; ++i)
        {
            scanf("%d", &balls[i]);
            for (int j = i - 1; j >= 0; --j)
                able[abs(balls[i] - balls[j])] = true;
        }
        
        bool valid(true);
        
        for (int i = 1; i < N + 1; ++i)
            if (!able[i])
                valid = false;
        
        if (valid)
            printf("Y\n");
        else
            printf("N\n");
    }
}