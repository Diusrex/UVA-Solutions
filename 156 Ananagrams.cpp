#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> letterBase(26, 0);

vector<int> GetLetterCounts(string word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        ++letterCounts[tolower(*iter) - 'a'];
    }
    
    return letterCounts;
}

bool Equal(const vector<int>& first, const vector<int>& second)
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
    string word;
    vector<string> words;
    vector<vector<int> > letterCounts;
    
    while (cin >> word, word != "#")
    {
        words.push_back(word);
        letterCounts.push_back(GetLetterCounts(word));
    }
    
    vector<bool> ananagram(words.size(), true);
    
    for (int i = 0; i < words.size(); ++i)
    {
        if (ananagram[i])
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (Equal(letterCounts[i], letterCounts[j]))
                {
                    ananagram[i] = false;
                    ananagram[j] = false;
                }
            }
        }
    }
    
    vector<string> allAnanagrams;
    
    for (int i = 0; i < words.size(); ++i)
    {
        if (ananagram[i])
        {
            allAnanagrams.push_back(words[i]);
        }
    }
    
    sort(allAnanagrams.begin(), allAnanagrams.end());
    
    for (int i = 0; i < allAnanagrams.size(); ++i)
    {
        cout << allAnanagrams[i] << '\n';
    }
}