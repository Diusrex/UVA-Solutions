#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int FindSolution(const vector<vector<int> > & numCharacters, int largestWordSize)
{
    int xSize, ySize;
    cin >> xSize >> ySize;
    int numPg = numCharacters.size();
    int maxSize = min(xSize / largestWordSize, ySize / numPg);
    
    for (int fontSize = min(28, maxSize); fontSize >= 8; --fontSize)
    {
        int numberLines = 0;
        
        for (int currentPg = 0; currentPg < numPg; ++currentPg)
        {
            ++numberLines;
            int sizeOfLine = -fontSize;
            
            for (int i = 0; i < numCharacters[currentPg].size(); ++i)
            {
                int currentSize = numCharacters[currentPg][i] * fontSize;
                if (sizeOfLine + currentSize > xSize)
                {
                    sizeOfLine = -fontSize;
                    ++numberLines;
                }
                
                sizeOfLine += currentSize;
            }
        }
        
        if (numberLines * fontSize <= ySize)
            return fontSize;
    }
    
    
    return 0;
}

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        int numPg;
        cin >> numPg;
        cin.ignore();
        
        // Includes the space
        vector<vector<int> > numCharacters(numPg);
        
        int largestWordSize = 0;
        
        string line;
        for (int i = 0; i < numPg; ++i)
        {
            getline(cin, line);
            stringstream ss(line);
            
            while (ss >> line)
            {
                numCharacters[i].push_back(line.size() + 1);
                if (line.size() > largestWordSize)
                    largestWordSize = line.size();
            }
        }
    
        int solution = FindSolution(numCharacters, largestWordSize);
        
        if (solution)
            cout << solution << '\n';
        else
            cout << "No solution\n";
        
    }
}