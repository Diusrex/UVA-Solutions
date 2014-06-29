#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const vector<int> letterBase(26, 0);

vector<int> GetLetterCounts(string word)
{
    vector<int> letterCounts(letterBase);
    
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (*iter != ' ')
            ++letterCounts[*iter - 'A'];
    }
    
    return letterCounts;
}

vector<bool> GetMayBeAdded(const string& line, const vector<string>& dictionary)
{
    istringstream iss(line);
    
    vector<string> words; 
    
    string temp;
    
    while (iss >> temp)
        words.push_back(temp);
    
    int size = dictionary.size();
    
    vector<bool> mayBeAdded(size, true);
    
    for (int dic = 0; dic < size; ++dic)
    {
        for (int word = 0; word < words.size(); ++word)
        {
            if (dictionary[dic] == words[word])
                mayBeAdded[dic] = false;
        }
    }
    
    return mayBeAdded;
}

void FindAnagrams(int currentPos, const string& phrase, vector<int> letterCountsLeft, vector<bool> wordAdded, const vector<vector<int> >& dictionaryCounts, const vector<string>& dictionary, const vector<bool>& mayBeAdded)
{
    bool allMet = true;
    
    for (int i = 0; i < 26; ++i)
    {
        letterCountsLeft[i] -= dictionaryCounts[currentPos][i];
        
        if (letterCountsLeft[i] < 0)
            return;
            
        else if (letterCountsLeft[i] > 0)
            allMet = false;
    }
    
    wordAdded[currentPos] = true;
    
    if (allMet)
    {
        cout << phrase << " =";
        
        for (int i = 0; i <= currentPos; ++i)
        {
            if (wordAdded[i])
                cout << ' ' << dictionary[i];
        }
        
        cout << '\n';
    }
    
    else
    {
        for (int i = currentPos + 1; i < dictionary.size(); ++i)
        {
            if (mayBeAdded[i])
                FindAnagrams(i, phrase, letterCountsLeft, wordAdded, dictionaryCounts, dictionary, mayBeAdded);
        }
    }
}

int main()
{
    vector<string> dictionary;
    vector<vector<int> > dictionaryCounts;
    string word;
    
    while (cin >> word, word != "#")
    {
        dictionary.push_back(word);
        dictionaryCounts.push_back(GetLetterCounts(word));
    }
    
    string phrase;
    
    cin.ignore();
    
    while (getline(cin, phrase), phrase != "#")
    {
        vector<bool> wordAdded(dictionary.size(), false);
        
        vector<int> count = GetLetterCounts(phrase);
        
        vector<bool> mayBeAdded = GetMayBeAdded(phrase, dictionary);
        
        for (int i = 0; i < dictionary.size(); ++i)
        {
            if (phrase != dictionary[i])
                FindAnagrams(i, phrase, count, wordAdded, dictionaryCounts, dictionary, mayBeAdded);
        }
    }
}