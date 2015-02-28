#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int M;

bool SortFunc(int i, int j)
{
    if (i % M != j % M)
        return i % M < j % M;
    if (i & 1) // i is odd
    {
        if (j & 1)
            return i > j;
        return true;
    }
    if (j & 1)
    {
        return false;
    }
    return i < j;
}

int main()
{
    int N;
    
    vector<int> numbers(10005);
    
    while (cin >> N >> M, cout << N << ' ' << M << '\n', N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
        }
        
        sort(numbers.begin(), numbers.begin() + N, SortFunc);
        ;
        for (int i = 0; i < N; ++i)
            cout << numbers[i] << '\n';
    }
}