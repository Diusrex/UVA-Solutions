#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const vector<int> letterBase(26, 0);

vector<int> GetLetterCounts(const string& word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        ++letterCounts[tolower(*iter) - 'a'];
    }
    
    return letterCounts;
}

bool AreEqual(const vector<int>& first, const vector<int>& second)
{
    for (int i = 0; i < 26; ++i)
    {
        if (first[i] != second[i])
            return false;
    }
    
    return true;
}

int main()
{
    vector<string> dictionaryWords; 
    
    string word;
    while (cin >> word, word != "XXXXXX")
    {
        dictionaryWords.push_back(word);
    }
    sort(dictionaryWords.begin(), dictionaryWords.end());
    
    vector<vector<int> > dictionaryLetters(dictionaryWords.size());
    
    for (int i = 0; i < dictionaryWords.size(); ++i)
        dictionaryLetters[i] = GetLetterCounts(dictionaryWords[i]);
    
    while (cin >> word, word != "XXXXXX")
    {
        vector<int> letterCounts = GetLetterCounts(word);
        
        bool match = false;
        
        for (int i = 0; i < dictionaryWords.size(); ++i)
        {
            if (AreEqual(letterCounts, dictionaryLetters[i]))
            {
                cout << dictionaryWords[i] << '\n';
                match = true;
            }
        }
        
        if (!match)
            cout << "NOT A VALID WORD\n";
            
        cout << "******\n";
    }
}