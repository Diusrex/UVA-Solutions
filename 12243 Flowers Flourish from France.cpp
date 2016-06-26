#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line), line != "*")
    {
        char needed = tolower(line[0]);
        
        bool allEqual = true;
        for (int i = 0; i < line.size(); ++i)
            if (line[i] == ' ')
            {
                if (i + 1 < line.size() && tolower(line[i + 1]) != needed)
                {
                    allEqual = false;
                    break;
                }
            }
        
        cout << (allEqual ? 'Y' : 'N') << '\n';
    }
}