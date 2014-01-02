#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T, count, numPieces;
    
    cin >> T;
    cin.ignore();
    
    string temp;
    
    while (T--)
    {
        count = numPieces = 0;
        
        getline(cin, temp);
        
        for (string::iterator iter = temp.begin(); iter != temp.end(); ++iter)
        {
            if (*iter == 'M')
                ++count;
            else if (*iter == 'F')
                --count;
        }
        
        if (count == 0 && temp.size() > 3)
            cout << "LOOP\n";
        else
            cout << "NO LOOP\n";
    }
}