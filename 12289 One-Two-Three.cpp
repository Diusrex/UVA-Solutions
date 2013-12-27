#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    string temp;
    
    cin >> T;
    
    while (T--)
    {
        cin >> temp;
        
        if (temp.length() == 5)
            cout << "3\n";
        
        else
        {
            int oneCorrect(0);
            
            if (temp[0] == 'o')
                ++oneCorrect;
            
            if (temp[1] == 'n')
                ++oneCorrect;
                
            if (temp[2] == 'e')
                ++oneCorrect;
            
            if (oneCorrect >= 2)
                cout << "1\n";
            else
                cout << "2\n";
        
        }
    
    }

}