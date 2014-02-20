#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool notPicked[26], guessed[26];
    int numDiff, wrong;
    
    int t;
    
    string word, input;
    while (cin >> t, t != -1)
    {
        for (int i(0); i < 26; ++i)
            notPicked[i] = guessed[i] = false;
         
        numDiff = wrong = 0;
        
        cin >> word >> input;
        
        for (string::iterator iter = word.begin(); iter != word.end(); ++iter)
        {
            if (!notPicked[*iter - 'a'])
            {
                notPicked[*iter - 'a'] = true;
                ++numDiff;
            }
        }
        
        for (string::iterator iter = input.begin(); iter != input.end() && wrong < 7 && numDiff; ++iter)
        {
            if (notPicked[*iter - 'a'])
            {
                notPicked[*iter - 'a'] = false;
                
                // Assuming that guessing a word a second time changes nothing
                guessed[*iter - 'a'] = true;
                --numDiff;
            }
            
            else if (!guessed[*iter - 'a'])
            {
                guessed[*iter - 'a'] = true;
                ++wrong;
            }
        }
        cout << "Round " << t << '\n';
        
        if (!numDiff)
            cout << "You win.\n";
            
        else if (wrong == 7)
            cout << "You lose.\n";
            
        else
            cout << "You chickened out.\n";
    }
}