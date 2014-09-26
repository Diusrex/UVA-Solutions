#include <iostream>
#include <cmath>

using namespace std;

const int BEST = 5;

int main()
{
    int T; 
    cin >> T;
    
    while (T--)
    {
        unsigned long long num = 0;
        int p, q;
        cin >> p >> q;
        
        int numBest = min(p / 2, q);
        if (numBest != 0)
        {
            p -= 2 * numBest;
            q -= numBest;
            
            if (p > 0 && q > 0)
            {
                num += 1;
                --p;
            }
            
            while (numBest--)
            {
                num <<= 3;
                num += BEST;
            }
        }
        while (p--)
        {
            num <<= 1;
            ++num;
        }
        
        cout << num << '\n';
    }
}