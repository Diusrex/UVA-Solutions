#include <iostream>

using namespace std;

int main()
{
    int T;

    cin >> T;
    
    while (T--)
    {
        int numFarmers;
        cin >> numFarmers;
        
        long long sum(0);
        
        while (numFarmers--)
        {
            long long area, blank, premium;
            cin >> area >> blank >> premium;
            sum += area * premium;
        }
        cout << sum << '\n';
    }

}