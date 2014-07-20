#include <iostream>
#include <string>

const int CORRECT_COUNT = 64;

const char DELIM = '/';

using namespace std;

int main()
{
    // There will be 64 #'s in a correct measure
    int noteValues[128];
    noteValues['W'] = 64;
    noteValues['H'] = 32;
    noteValues['Q'] = 16;
    noteValues['E'] = 8;
    noteValues['S'] = 4;
    noteValues['T'] = 2;
    noteValues['X'] = 1;
    
    string line;
    while (cin >> line, line != "*")
    {
        int correct = 0, currentCount = 0;
        
        for (int pos = 0; pos < line.size(); ++pos)
        {
            if (line[pos] == DELIM)
            {
                if (currentCount == CORRECT_COUNT)
                    ++correct;
                currentCount = 0;
            }
            
            else
            {
                currentCount += noteValues[line[pos]];
            }
        }
        
        cout << correct << '\n';
    }
}