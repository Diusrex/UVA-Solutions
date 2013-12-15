#include <iostream>
#include <string>

using namespace std;


int main()
{
    string temp;
    
    getline(cin, temp);
    
    while (temp[0] != '|')
        getline(cin, temp);
    
    
    while (temp[0] == '|')
    {
        int pos(7);
        
        int value(0);
        
        for (string::const_iterator c = temp.begin() + 1; pos >= 0; ++c)
        {
            if (*c == ' ' || *c == 'o')
            {
                if (*c == 'o')
                    value += (1 << pos);
                    
                --pos;
            }
        
        }
        
        cout << static_cast<char>(value);
        getline(cin, temp);
    }

}