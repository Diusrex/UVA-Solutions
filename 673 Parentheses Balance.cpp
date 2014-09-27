#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsValid(const string & line)
{
    string::const_iterator iter = line.begin();
    stack<char> stuff;
        
    while (iter != line.end())
    {
        if (*iter == ')')
        {
            if (stuff.empty() || stuff.top() != '(')
                return false;
            stuff.pop();
        }
        else if (*iter == ']')
        {
            if (stuff.empty() || stuff.top() != '[')
                return false;
            stuff.pop();
        }
        else
            stuff.push(*iter);
        ++iter;
    }
    
    return stuff.empty();
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    string line;
    while (T--)
    {
        getline(cin, line);
        
        if (IsValid(line))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}