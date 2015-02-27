#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

vector<vector<string> > allLinesWords;

struct KeyWord
{
    int wordPos;
    int linePos;
    
    KeyWord(int wordPos, int linePos)
        : wordPos(wordPos),
        linePos(linePos)
    { }
   
    bool operator<(const KeyWord & other) const
    {
        if (allLinesWords[linePos][wordPos] != allLinesWords[other.linePos][other.wordPos])
            return allLinesWords[linePos][wordPos] < allLinesWords[other.linePos][other.wordPos];
        if (linePos != other.linePos)
            return linePos < other.linePos; 

        return wordPos < other.wordPos;
    }
};

set<string> ignored;
vector<KeyWord> allKeywords;

void GenerateWordsAndKeyWords(const string &line)
{
    stringstream ss(line);
    
    string word;
    int linePos = allLinesWords.size();
    allLinesWords.push_back(vector<string>());
    
    int wordPos = 0;
    while (ss >> word)
    {
        allLinesWords[linePos].push_back(word);
        
        if (ignored.find(word) == ignored.end())
        {
            allKeywords.push_back(KeyWord(wordPos, linePos));
        }
        
        ++wordPos;
    }
}


void PrintOutKeyword(const KeyWord &keyword)
{
    string sep = "";
    vector<string> &line = allLinesWords[keyword.linePos];
    
    for (int wordPos = 0; wordPos < line.size(); ++wordPos)
    {
        string &word = line[wordPos];
        if (wordPos != keyword.wordPos)
            cout << sep << word;
        else
        {
            cout << sep;
            for (int i = 0; i < word.size(); ++i)
                cout << (char)toupper(word[i]);
        }
        
        sep = " ";
    }
    cout << '\n';
}

int main()
{
    string word;
    while (cin >> word, word != "::")
        ignored.insert(word);
    
    cin.ignore();
    
    string line;
    
    while (getline(cin, line))
    {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        GenerateWordsAndKeyWords(line);
    }
    
    sort(allKeywords.begin(), allKeywords.end());
    
    for (int i = 0; i < allKeywords.size(); ++i)
    {
        PrintOutKeyword(allKeywords[i]);
    }
}