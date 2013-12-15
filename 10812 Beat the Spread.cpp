#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        int sum, diff;
        cin >> sum >> diff;
        
        int a((sum + diff) / 2);
        
        int b(sum - a);
        
        if (b < 0 || a - b != diff)
            cout << "impossible\n";
            
        else
            cout << a << " " << b << '\n';
    }   

}