#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct LetterFreq
{
    LetterFreq(char character)
        : character(character),
        freq(1)
    { }
    
    int freq;
    char character;
    
    bool operator<(const LetterFreq & other) const
    {
        return freq < other.freq;
    }
};

using namespace std;

void SetUpFrequency(string str, vector<LetterFreq>& sortedFreq)
{    
    sort(str.begin(), str.end());
    sortedFreq.clear();
    
    sortedFreq.push_back(LetterFreq(str[0]));
    
    int pos = 0;
    for (int i = 1; i < str.size(); ++i)
    {
        
        if (str[i] != sortedFreq[pos].character)
        {
            sortedFreq.push_back(LetterFreq(str[i]));
            ++pos;
        }
        else
            ++sortedFreq[pos].freq;
    }
    
    sort(sortedFreq.begin(), sortedFreq.end());
}

int main()
{
    int T;
    string sep = "";
    cin >> T;
    
    string origional, translated;
    vector<LetterFreq> origionalFreq, translatedFreq;
    map<char, char> translatedToOrigional;
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        cin >> origional >> translated;
        
        SetUpFrequency(origional, origionalFreq);
        SetUpFrequency(translated, translatedFreq);
        translatedToOrigional.clear();
        
        for (int i = 0; i < origionalFreq.size(); ++i)
            translatedToOrigional[translatedFreq[i].character] = origionalFreq[i].character;
        
        for (string::iterator iter = translated.begin(); iter != translated.end(); ++iter)
        {
            *iter = translatedToOrigional[*iter];
        }
        
        cout << translated << '\n';
    }
}