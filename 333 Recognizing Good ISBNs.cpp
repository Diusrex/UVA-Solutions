#include <iostream>
#include <string>

using namespace std;

inline bool IsInt(const char & character) { return character >= '0' && character <= '9'; } 

const int NUM_NEEDED_DIGITS = 10;

void TrimLine(string & line)
{
    size_t endpos = line.find_last_not_of(" \t");
    if (string::npos != endpos)
    {
        line = line.substr( 0, endpos+1 );
    }
    size_t startpos = line.find_first_not_of(" \t");
    if( string::npos != startpos )
    {
        line = line.substr( startpos );
    }
}

bool IsValid(const string & word)
{
    int numNumbers= 0;
    int s1 = 0, s2 = 0;
    string::const_iterator iter = word.begin();
    
    // Need to load and sum all of the sum digits
    while (iter != word.end() && numNumbers < NUM_NEEDED_DIGITS)
    {
        if (IsInt(*iter))
        {
            ++numNumbers;
            s1 += *iter - '0';
            s2 += s1;
        }
        
        else if (numNumbers + 1 == NUM_NEEDED_DIGITS && *iter == 'X')
        {
            ++numNumbers;
            s1 += 10;
            s2 += s1;
        }
        
        else if (*iter != '-')
            return false;
            
        ++iter;
    }
    if (numNumbers != NUM_NEEDED_DIGITS)
        return false;
        
    if (s2 % 11 != 0)
        return false;
    
    while (iter != word.end())
    {
        if (*iter != '-')
            return false;
        ++iter;
    }
    
    return true;
}

int main()
{
    string line;
    
    while (getline(cin, line))
    {
        TrimLine(line);
        
        if (IsValid(line))
            cout << line << " is correct.\n";
        else
            cout << line << " is incorrect.\n";
    }
}