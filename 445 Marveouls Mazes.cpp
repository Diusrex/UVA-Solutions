#include <iostream>

using namespace std;

int main()
{
    string line;
    
    getline(cin, line);
    
    while (!cin.eof())
    {
        int number(0);
        
        for (string::iterator iter = line.begin(); iter != line.end(); ++iter)
        {
            if (*iter == 'b')
                *iter = ' ';
                
            if (*iter >= '0' && *iter <= '9')
                number += (*iter - '0');
            
            else if (*iter == '!')
                cout << '\n';
            
            else
            {
                for (int i = 0; i < number; ++i) { cout << *iter; }
                number = 0;            
            }
        }
        
        cout << '\n';
        getline(cin, line);
    }
}