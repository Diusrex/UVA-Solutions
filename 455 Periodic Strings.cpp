#include <string>
#include <iostream>

using namespace std;

bool StringIsSame(const string & str, int diffBetween)
{
    for (int i = 0; i < diffBetween; ++i)
    {
        const char & expected = str[i];
        
        for (int j = i + diffBetween; j < str.size(); j += diffBetween)
            if (str[j] != expected)
                return false;
    }
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    string sep = "";
    
    string line;
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        cin >> line;
        int i;
        for (i = 1; i < line.size(); ++i)
        {
            if (line.size() % i != 0)
                continue;
            
            if (StringIsSame(line, i))
            {
                cout << i << '\n';
                break;
            }
        }
        
        if (i == line.size())
            cout << i << '\n';
    }
}