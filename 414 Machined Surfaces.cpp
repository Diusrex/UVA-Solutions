#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N;
    
    while (cin >> N, N)
    {
        cin.ignore();
        
        vector<int> spaces(N);
        int minSpaces = -1;
        
        string line;
        
        for (int i = 0; i < N; ++i)
        {
            getline(cin, line);
            int spaceCount = 0;
            for (string::const_iterator iter = line.begin(); iter != line.end(); ++iter)
            {
                if (*iter != 'X')
                    ++spaceCount;
            }
            
            spaces[i] = spaceCount;
            if (spaceCount < minSpaces || minSpaces == -1)
                minSpaces = spaceCount;
        }
        
        int total = 0;
        for (int i = 0; i < N; ++i)
            total += spaces[i] - minSpaces;
            
        cout << total << '\n';
    }
}