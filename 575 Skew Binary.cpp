#include <iostream>

using namespace std;

int main()
{
    int value, multiplyer;
    string input;
    
    while (getline(cin, input), input != "0")
    {
        value = 0;
        multiplyer = 2;
        
        for (int i = input.size() - 1; i >=0; --i, multiplyer *= 2)
        {
            value += (input[i] - '0') * (multiplyer - 1);
        }
        
        cout << value << '\n';
    }
}