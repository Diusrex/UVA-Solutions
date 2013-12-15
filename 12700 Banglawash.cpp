#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int n, numB(0), numW(0), numA(0), numD(0);
        
        cin >> n;
        
        for (int i = 0; i < n; ++i)
        {
            char input;
            cin >> input;
            switch (input)
            {
            case 'B':
                ++numB;
                break;
            case 'W':
                ++numW;
                break;
            case 'A':
                ++numA;
                break;
            default:
                ++numD;
                break;
            }
        }
        
        cout << "Case " << t << ": ";
        
        if (numA == n)
            cout << "ABANDONED";
        else if (numB == numW)
            cout << "DRAW " << numB << ' ' << numD;
        else if (numW + numA == n)
            cout << "WHITEWASH";
        else if (numB + numA == n)
            cout << "BANGLAWASH";
        else
        {
            if (numB > numW)
                cout << "BANGLADESH " << numB << " - " << numW;
            else
                cout << "WWW " << numW << " - " << numB;
        }
        cout << '\n';
    }

}