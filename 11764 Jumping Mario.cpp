#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int n;
        
        cin >> n;
        
        int increase(0), decrease(0);
        
        int previous, current;
        
        cin >> previous;
        
        for (int i = 1; i < n; ++i)
        {
            cin >> current;
            
            if (current > previous)
                ++increase;
            else if (current < previous)
                ++decrease;
            
            previous = current;       
        }
        
        cout << "Case " << t << ": " << increase << " " << decrease <<'\n';
    }

}