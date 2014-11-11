#include <iostream>

using namespace std;



int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int sum = 0;
        
        for (int i = 0; i < 4; ++i)
        {
            int num;
            cin >> num;
            
            for (int j = 0; j < 2; ++j)
            {
                sum += num % 10;
                num /= 10;
                sum += num * 2 % 10;
                sum += (num % 10 * 2 / 10);
                num /= 10;
            }
        }
        
        if (sum % 10)
            cout << "Invalid\n";
        else
            cout << "Valid\n";
    }
}