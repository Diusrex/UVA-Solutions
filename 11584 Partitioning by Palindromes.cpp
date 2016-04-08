#include <iostream>
#include <string>

using namespace std;

string word;

// Assuming we start paritioning from here, what is the last number possible
int leastGroups[1005];

int GetNumGroups(int currentNode)
{
    if (currentNode == word.size())
        return 0;
    
    int &leastGroup = leastGroups[currentNode];
    if (leastGroup == 0)
    {
        // Higher number than possible
        leastGroup = 20000;
        for (int length = word.size() - currentNode; length > 0; --length)
        {
            // Includes the finalNode
            int finalNode = currentNode + length - 1;
            bool possible = true;
            for (int i = 0; i < length / 2; ++i)
            {
                if (word[currentNode + i] != word[finalNode - i])
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                leastGroup = min(leastGroup, GetNumGroups(finalNode + 1));
            }
        }
        // Include self
        ++leastGroup;
    }
    
    return leastGroup;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> word;
        for (int i = 0; i < word.size(); ++i)
            leastGroups[i] = 0;
        
        cout << GetNumGroups(0) << '\n';
    }
}