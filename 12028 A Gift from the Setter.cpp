#include <iostream>
#include <algorithm>

using namespace std;

long long numbers[100005];
const int Mod = 1000007;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int K, C, N;
        cin >> K >> C >> N >> numbers[0];
        
        for (int i = 1; i < N; ++i)
            numbers[i] = (K * numbers[i- 1] + C) % Mod;
        
        sort(numbers, numbers + N);
        
        long long prevDiff = 0, total = 0;
        
        for (int i = 1; i < N; ++i)
        {
            prevDiff += (numbers[i] - numbers[i - 1]) * i;
            total += prevDiff;
        }
        
        cout << "Case " << t << ": " << total << '\n';
    }
}