#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int num;
        cin >> num;
        
        bool foundOne(false);
        
        cout << "Case #" << t << ": " << num << " = ";
        
        int i = 2;
        for (; i < num; ++i)
        {
            if (num % i == 0)
            {
                if (!foundOne)
                {
                    cout << i << " * " << num / i << " = ";
                    foundOne = true;
                }
                else
                    break;
            }
           
        }
        
        cout << i << " * " << num / i << '\n';
    }

}