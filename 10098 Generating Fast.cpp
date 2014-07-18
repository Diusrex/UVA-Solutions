#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool string_comp(const char& lhs, const char& rhs)
{
    if (lhs >= 'A')
    {
        return (rhs < 'A' || lhs < rhs);
    }
    else
    {
        return (rhs < 'A' && lhs < rhs);
    }
}

int main()
{
    int T;
    cin >> T;
    
    string word;
    
    while (T--)
    {
        cin >> word;
        
        sort(word.begin(), word.end(), string_comp);
        
        do
        {
            cout << word << '\n';
        } while (next_permutation(word.begin(), word.end(), string_comp));
        
        cout << '\n';
    }
}