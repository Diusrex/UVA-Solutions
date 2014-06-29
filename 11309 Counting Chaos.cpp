#include <iostream>
#include <string>

using namespace std;

void Tick(string& number)
{
    number[3] += 1;
    
    if (number[3] > '9')
    {
        number[3] = '0';
        number[2] += 1;
        
        if (number[2] == '6')
        {
            number[2] = '0';
            
            number[1] += 1;
            
            if (number[1] > '9' || (number[0] == '2' && number[1] == '4'))
            {
                number[1] = '0';
                
                number[0] += 1;
                
                if (number[0] == '3')
                {
                    number[0] = '0';
                }
            }
        }
    }
}

bool IsPalindrome(const string& number)
{
    int start = 0, end = 3;
    
    while (number[start] == '0')
        ++start;
        
    while (start < end)
    {
        if (number[start++] != number[end--])
            return false;
    }
    
    return true;
}


int main()
{
    int T;
    cin >> T;
    
    string number;
    
    while (T--)
    {
        cin >> number;
        number.erase(2, 1);
        
        Tick(number);
        
        while (!IsPalindrome(number))
            Tick(number);
        
        cout << number[0] << number[1] << ':' << number[2] << number[3] << '\n';
    }
}