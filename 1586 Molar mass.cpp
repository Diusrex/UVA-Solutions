#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

double weights[128];

int main()
{
    weights['C'] = 12.01;
    weights['H'] = 1.008;
    weights['O'] = 16;
    weights['N'] = 14.01;
    
    int T;
    cin >> T;
    
    while (T--)
    {
        string str;
        cin >> str;
        
        double totalWeight = 0;
        
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] > '9')
                totalWeight += weights[str[i]];
            
            else
            {
                double currentWeight = weights[str[i - 1]];
                
                // Already added it once
                int mult = atoi(str.c_str() + i) - 1;
                totalWeight += currentWeight * mult;
                
                // Would be more efficient to advance i here, but is not necessary
            }
        }
        
        cout << setprecision(3) << fixed << totalWeight << '\n';
    }    
}