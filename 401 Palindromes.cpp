#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<char, char> reverse;
    reverse['A'] = 'A'; reverse['E'] = '3'; reverse['H'] = 'H'; reverse['I'] = 'I'; reverse['J'] = 'L';
    reverse['L'] = 'J'; reverse['M'] = 'M'; reverse['O'] = 'O'; reverse['S'] = '2'; reverse['T'] = 'T';
    reverse['U'] = 'U'; reverse['V'] = 'V'; reverse['W'] = 'W'; reverse['X'] = 'X'; reverse['Y'] = 'Y';
    reverse['Z'] = '5'; reverse['1'] = '1'; reverse['2'] = 'S'; reverse['3'] = 'E'; reverse['5'] = 'Z';
    reverse['8'] = '8';
    
    
    string word;
    
    while (cin >> word)
    {
        bool palindrome(true), mirror(true);
        
        for (string::iterator front = word.begin(), end = word.end() - 1; front <= end; ++front, --end)
        {
            if (*front != *end)
                palindrome = false;
            
            if (reverse.find(*front) == reverse.end() || reverse[*front] != *end)
                mirror = false;
        }   
        
        cout << word << " -- is ";
        
        if (palindrome && mirror)
            cout << "a mirrored palindrome.";
        else if (palindrome)
            cout << "a regular palindrome.";
        else if (mirror)
            cout << "a mirrored string.";
        else
            cout << "not a palindrome.";
        cout << "\n\n";
    }
 
}