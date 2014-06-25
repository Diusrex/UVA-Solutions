#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string Convert(const std::string& line)
{
    string phrase = "";
    
    for (int i = 0; i < line.size(); ++i)
    {
        if (line[i] >= 'a' && line[i] <= 'z')
            phrase += line[i];
    }
    
    return phrase;
}

int MagicBoxSize(const std::string phrase)
{
    int boxSize = sqrt(phrase.size());
    
    if (boxSize * boxSize != phrase.size())
        return 0;
    
    int end = phrase.size() - 1;
    int goTo = phrase.size() / 2;
    
    for (int main = 0, vertical = 0; main <= goTo; ++main, vertical = (vertical + boxSize) % end)
    {
        if (phrase[main] != phrase[end - main])
        {
            return 0;
        }
    }
    
    return boxSize;
}


int main()
{
    string line;
    string phrase;
    
    int T;
    cin >> T;
    cin.ignore();
    
    for (int t = 1; t <= T; ++t)
    {
        getline(cin, line);
        
        phrase = Convert(line);
        
        cout << "Case #" << t << ":\n";
        
        int size = MagicBoxSize(phrase);
        
        if (size)
            cout << size << '\n';
        else
            cout << "No magic :(\n";
    }
}