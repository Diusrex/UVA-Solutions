#include <iostream>

using namespace std;
// [egg][weightAfter] -> best number to be added
// Includes this egg

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int N, P, Q;
        cin >> N >> P >> Q;
        
        int sum = 0, numUsed = 0;
        int i, weight;
        
        for (i = 0; i < N && sum <= Q; ++i, ++numUsed)
        {
            cin >> weight;
            sum += weight;
        }
        
        if (sum > Q)
        {
            --numUsed;
            for (; i < N; ++i)
                cin >> weight;
        }
        
        cout << "Case " << t << ": " << min(numUsed, P) << '\n';
    }
}