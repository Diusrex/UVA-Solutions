#include <iostream>

using namespace std;

typedef unsigned long long ull;

int deg;
int coefficients[21];

ull eval(int n, ull currentNPowVals, int coeff)
{
    if (coeff > deg)
        return 0;
    
    return coefficients[coeff] * currentNPowVals + eval(n, n * currentNPowVals, coeff + 1);
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> deg;
        for (int i = 0; i <= deg; ++i)
            cin >> coefficients[i];
        
        int d, k;
        cin >> d >> k;
        
        int position = 1, inc = d, count = 1;
        
        for (; count <= k; ++position, inc += d)
        {
            count += inc;
        }
        
        cout << eval(position - 1, 1, 0) << '\n';
    }
}