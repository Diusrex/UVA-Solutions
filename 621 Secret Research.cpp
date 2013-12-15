#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        string input;
        cin >> input;
        
        
        if (input == "1" || input == "4" || input == "78")
            cout << "+";
        
        else if (*(input.end() - 2) == '3' && *(input.end() - 1) == '5')
            cout << '-';
        else if (input[0] == '9' && *(input.end() - 1) == '4')
            cout << '*';
        else
            cout << '?';
        
        cout << '\n';
    }

}