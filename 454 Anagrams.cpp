#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool lexicographic(const string& first, const string& second)
{
    return lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
}

const vector<int> letterBase(128, 0);

vector<int> GetLetterCounts(string word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (*iter != ' ')
            ++letterCounts[*iter];
    }
    
    return letterCounts;
}

bool Equal(const vector<int>& first, const vector<int>& second)
{
    for (int i = 0; i < 128; ++i)
        if (first[i] != second[i])
            return false;
    return true;
}

int main()
{
    int T;
    
    cin >> T;
    
    cin.ignore();
    
    string temp;
    getline(cin, temp);
    
    string separator = "";
    while (T--)
    {
        vector<string> phrases;
        
        while (getline(cin, temp) && temp != "")
        {
            phrases.push_back(temp);
        }
        
        sort(phrases.begin(), phrases.end(), lexicographic);
        
        vector<vector<int> > letterCounts(phrases.size());
        
        for (int i = 0; i < phrases.size(); ++i)
            letterCounts[i] = GetLetterCounts(phrases[i]);
        
        cout << separator;
        separator = "\n";
        
        for (int i = 0; i < phrases.size(); ++i)
        {
            for (int j = i + 1; j < phrases.size(); ++j)
            {
                if (Equal(letterCounts[i], letterCounts[j]))
                    cout << phrases[i] << " = " << phrases[j] << '\n';
            }
        }
    }

}