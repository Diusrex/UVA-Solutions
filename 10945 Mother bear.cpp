#include <iostream>
#include <string>

using namespace std;

bool IsInvalid(const char& letter)
{
    return (letter == '.' || letter == ',' || letter == '!' || letter == '?' || letter == ' ');
}

bool IsPalindrome(const string& word)
{
    int start = 0;
    int end = word.size() -1;
    
    while (start < end && IsInvalid(word[start]))
        ++start;
        
    
    while (end > start && IsInvalid(word[end]))
        --end;
        
    while (start < end)
    {
        if (tolower(word[start]) != tolower(word[end]))
            return false;
        
        ++start;
        --end;
        
        while (start < end && IsInvalid(word[start]))
            ++start;
        
        while (end > start && IsInvalid(word[end]))
            --end;
    }
}
int main()
{
    string word;
    
    while (getline(cin, word), word != "DONE")
    {
        if (IsPalindrome(word))
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
}