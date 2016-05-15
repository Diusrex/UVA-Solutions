#include <iostream>

using namespace std;

int main()
{
    int t = 1;
    
    int N, R;
    
    while (cin >> R >> N, N)
    {
        --R;
        cout << "Case " << t++ << ": ";
        if (R / N > 26)
            cout << "impossible\n";
        else
            cout << R / N << '\n';
    }
}