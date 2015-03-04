#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        if (t != 1)
            cout << '\n';
        
        int n;
        cin >> n;
        cin.ignore();
        cout << "Case " << t << ":\n";
        
        while (n--)
        {
            string origional = "", newStr = "";
            getline(cin, origional);
            
            bool previousSpace = false;
            
            for (string::iterator iter = origional.begin(); iter != origional.end(); ++iter)
            {
                if (*iter == ' ')
                {
                    if (!previousSpace)
                        newStr += *iter;
                    
                    previousSpace = true;
                }
                else
                {
                    newStr += *iter;
                    previousSpace = false;
                }
            }
            
            cout << newStr << '\n';
        }
    }
}