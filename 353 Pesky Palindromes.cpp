#include <iostream>
#include <string>
#include <set>

using namespace std;

bool IsPalindrome(const string& word)
{
    int start = 0;
    int end = word.size() - 1;
    
    while (start < end)
    {
        if (word[start] != word[end])
            return false;
        ++start;
        --end;
    }
    
    return true;
}

int main()
{
    string word;
    
    while (getline(cin, word))
    {
        set<string> usedPalindromes;
        
        int count = 0;
        
        for (int start = 0; start < word.size(); ++start)
        {
            string subSequence = "";
            
            for (int toAdd = start; toAdd < word.size(); ++toAdd)
            {
                subSequence += word[toAdd];
                
                if (IsPalindrome(subSequence) && usedPalindromes.find(subSequence) == usedPalindromes.end())
                {
                    ++count;
                    usedPalindromes.insert(subSequence);
                }
            }
        }
        
        cout << "The string '" << word << "' contains " << count << " palindromes.\n";
    }
}