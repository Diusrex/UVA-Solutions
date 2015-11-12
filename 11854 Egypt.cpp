#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c, a)
    {
        int asq = a * a, bsq = b * b, csq = c * c;
        
        if (asq + bsq == csq || asq + csq == bsq || bsq + csq == asq)
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}