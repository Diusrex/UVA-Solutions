#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        long long first, second, third;
        
        cin >> first >> second >> third;
        
        cout << "Case " << t << ": ";
        
        if (first <= 0 || second <= 0 || third <= 0)
            cout << "Invalid";
            
        else if (first + second <= third || first + third <= second || second + third <= first)
            cout << "Invalid";
            
        else if (first == second && second == third)
            cout << "Equilateral";
        
        else if (first == second || first == third || second == third)
            cout << "Isosceles";
                
        else
            cout << "Scalene";
            
        cout << '\n';
    }

}