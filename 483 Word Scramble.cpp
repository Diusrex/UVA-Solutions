#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    bool isFirst = true;

    while (!cin.eof())
    {
        getline(cin, line);
        
        if (line[line.size() - 1] == 0xD)
            line = line.substr(0, line.size() - 1);

        int start = 0;
        while (start < line.size() && line[start] == ' ')
            ++start;

        int end = line.find(' ', start);
        while (start < line.size())
        {
            reverse(line.begin() + start, line.begin() + end);

            start = end + 1;
            while (start < line.size() && line[start] == ' ')
                ++start;

            end = line.find(' ', start);
            if (end == string::npos)
                end = line.size();
        }

        if (!isFirst)
            cout << endl;
        cout << line;
        isFirst = false;
    }
}
