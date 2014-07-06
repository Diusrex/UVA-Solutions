#include <iostream>
#include <iomanip>
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
    int T;
    cin >> T;
    
    string sep = "";
    
    while (T--)
    {
        int M;
        cin >> M;
        vector<string> vocabWords(M);
        vector<vector<int> > vocabLetterCounts(M);
        
        for (int i = 0; i < M; ++i)
        {
            cin >> vocabWords[i];
            vocabLetterCounts[i] = GetLetterCounts(vocabWords[i]);
        }
        
        string current;
        
        cout << sep;
        sep = "\n";
        
        while (cin >> current, current != "END")
        {
            cout << "Anagrams for: " << current << '\n';
            vector<int> letterCount = GetLetterCounts(current);
            
            int count = 1;
            
            for (int i = 0; i < M; ++i)
            {
                if (AreEqual(letterCount, vocabLetterCounts[i]))
                    cout << std::fixed << setw(3) << count++ << ") " << vocabWords[i] << '\n';
            }
            
            if (count == 1)
                cout << "No anagrams for: " << current << '\n';
        }
        
        
    }
}