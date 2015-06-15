#include <iostream>

using namespace std;

int GetVal(int v, int L)
{
    int count = 0;
    
    while (v > 1 && v <= L)
    {
        if (v & 1)
            v = 3 * v + 1;
        else
            v /= 2;
        ++count;
    }
    
    if (v == 1)
        ++count;
    
    return count;
}

int main()
{
    int A, L;
    int T = 1;
    
    while (cin >> A >> L, A != -1)
    {
        cout << "Case " << T++ << ": A = " << A << ", limit = " << L << ", number of terms = " << GetVal(A, L) << '\n';
    }
}