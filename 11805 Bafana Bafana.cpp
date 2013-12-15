#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        int N, K, P;
        cin >> N >> K >> P;
        --K;
        
        cout << "Case " << i << ": " << ((K + P) % N) + 1 << '\n';
    }

}