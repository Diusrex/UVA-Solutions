#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool vowel[128];

bool IsLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main()
{
    vowel['A'] = vowel['a'] = vowel['E'] = vowel['e'] = vowel['I'] = vowel['i'] 
        = vowel['O'] = vowel['o'] = vowel['U'] = vowel['u'] = true;
    
    string line, word, sep;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.size(); ++i)
        {
            if (IsLetter(line[i]))
            {
                char startingCharacter = line[i];
                if (vowel[startingCharacter])
                    cout << startingCharacter;
                
                ++i;
                for (; i < line.size() && IsLetter(line[i]); ++i)
                    cout << line[i];
                
                if (!vowel[startingCharacter])
                    cout << startingCharacter;
                
                cout << "ay";
                --i;
            }
            else
                cout << line[i];
        }
        
        cout << '\n';
    }
}
