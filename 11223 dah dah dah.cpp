#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

void SetUpMorseConverter(map<string, char> & morseConverter)
{
    morseConverter[".-"] = 'A'; morseConverter["-..."] = 'B'; morseConverter["-.-."] = 'C';
    morseConverter["-.."] = 'D'; morseConverter["."] = 'E'; morseConverter["..-."] = 'F';
    morseConverter["--."] = 'G'; morseConverter["...."] = 'H'; morseConverter[".."] = 'I';
    morseConverter[".---"] = 'J'; morseConverter["-.-"] = 'K'; morseConverter[".-.."] = 'L';
    morseConverter["--"] = 'M'; morseConverter["-."] = 'N'; morseConverter["---"] = 'O';
    morseConverter[".--."] = 'P'; morseConverter["--.-"] = 'Q'; morseConverter[".-."] = 'R';
    morseConverter["..."] = 'S'; morseConverter["-"] = 'T'; morseConverter["..-"] = 'U';
    morseConverter["...-"] = 'V'; morseConverter[".--"] = 'W'; morseConverter["-..-"] = 'X';
    morseConverter["-.--"] = 'Y'; morseConverter["--.."] = 'Z';
    morseConverter["-----"] = '0'; morseConverter[".----"] = '1'; morseConverter["..---"] = '2';
    morseConverter["...--"] = '3'; morseConverter["....-"] = '4'; morseConverter["....."] = '5';
    morseConverter["-...."] = '6'; morseConverter["--..."] = '7'; morseConverter["---.."] = '8';
    morseConverter["----."] = '9';
    morseConverter[".-.-.-"] = '.'; morseConverter["--..--"] = ','; morseConverter["..--.."] = '?';
    morseConverter[".----."] = '\''; morseConverter["-.-.--"] = '!'; morseConverter["-..-."] = '/';
    morseConverter["-.--."] = '('; morseConverter["-.--.-"] = ')'; morseConverter[".-..."] = '&';
    morseConverter["---..."] = ':'; morseConverter["-.-.-."] = ';'; morseConverter["-...-"] = '=';
    morseConverter[".-.-."] = '+'; morseConverter["-....-"] = '-'; morseConverter["..--.-"] = '_';
    morseConverter[".-..-."] = '"'; morseConverter[".--.-."] = '@';
}

int main()
{
    map<string, char> morseConverter;
    SetUpMorseConverter(morseConverter);
    
    int T;
    cin >> T;
    cin.ignore();
    
    string line, word, phrase;
    
    for (int t = 1; t <= T; ++t)
    {
        getline(cin, line);
        
        stringstream ss(line);
        int pos = 0;
        
        phrase = "";
        
        while (ss >> word)
        {
            phrase += morseConverter[word];
            pos += word.size() + 1;
            
            while (pos < line.size() && line[pos] == ' ')
            {
                phrase += ' ';
                ++pos;
            }
        }
        cout << "Message #" << t << '\n';
        cout << phrase << '\n';
        
        if (t != T)
            cout << '\n';
    }
}