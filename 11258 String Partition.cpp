#include <iostream>
#include <climits>

using namespace std;

int N;
// string should be length N + 1 appended
string str;
long long bestSum[201];

long long GetBest(int pos)
{
    if (pos == N)
        return 0;
    
    long long& best = bestSum[pos];
    if (best == -1)
    {
        best = 0;
        int end = pos + 1;
        long long amount = str[pos] - '0';
        while (amount <= INT_MAX && end <= N)
        {
            best = max(best, amount + GetBest(end));
            amount = amount * 10 + str[end] - '0';
            ++end;
        }
        
    }
    return best;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> str;
        N = str.size();
        str.push_back('-');
        for (int i = 0; i < N; ++i)
            bestSum[i] = -1;
        
        cout << GetBest(0) << '\n';
    }
}