#include <iostream>
#include <string>

using namespace std;

int main()
{
    string temp;
    bool isFirst(true);
    
    while (getline(cin, temp))
    {
        for (string::iterator iter = temp.begin(); iter != temp.end(); ++iter)
        {
            if (*iter == '"')
            {
                if (isFirst)
                    cout << "``";
                else
                    cout << "''";
                
                isFirst = !isFirst;            
            }
            else
                cout << *iter;
        }
        cout << '\n';
    }
    


}