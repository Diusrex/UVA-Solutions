#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        long long c;
        cin >> c;
        
        long long payment = 0;
        c -= 180000;
        
        if (c > 0)
        {
            payment += c * 10;
            c -= 300000;
            if (c > 0)
            {
                payment += c * 5;
                c -= 400000;
                if (c > 0)
                {
                    payment += c * 5;
                    c -= 300000;
                    if (c > 0)
                        payment += c * 5;
                }
            }
            
            if (payment % 100)
                payment += (100 - (payment % 100));
            else
                payment -= payment % 100;
                
            payment /= 100;
            
            if (payment < 2000)
                payment = 2000;
        }
        
        cout << "Case " << t << ": " << payment << '\n';
    }
}