#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool string_comp(const char& lhs, const char& rhs)
{

    if (tolower(lhs) == tolower(rhs))
        return lhs < rhs;
    else
        return tolower(lhs) < tolower(rhs);
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
    }
}