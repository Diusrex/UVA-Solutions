#include <iostream>
#include <vector>
#include <set>

using namespace std;

int longestCommonSeq[301][301];
int lengthIncluding[301][301];

string a, b;
// Indexed into a
vector<int> startOfLongest;

int GetLongest(int aIndex, int bIndex, int& longest)
{
    if (aIndex == a.size() || bIndex == b.size())
        return 0;
    int &longestAtPos = longestCommonSeq[aIndex][bIndex];
    
    if (longestAtPos == -1)
    {
        lengthIncluding[aIndex][bIndex] = 0;
        if (a[aIndex] == b[bIndex])
        {
            longestAtPos = GetLongest(aIndex + 1, bIndex + 1, longest);
            
            if (aIndex + 1 == a.size() || bIndex + 1 == b.size())
                lengthIncluding[aIndex][bIndex] = 1;
            else
                lengthIncluding[aIndex][bIndex] = 1 + lengthIncluding[aIndex + 1][bIndex + 1];
            
            longestAtPos = max(longestAtPos, lengthIncluding[aIndex][bIndex]);
            
            if (lengthIncluding[aIndex][bIndex] == longest)
            {
                startOfLongest.push_back(aIndex);
            }
            else if (lengthIncluding[aIndex][bIndex] > longest)
            {
                longest = lengthIncluding[aIndex][bIndex];
                startOfLongest.assign(1, aIndex);
            }
        }
        
        longestAtPos = max(longestAtPos, max(
                           GetLongest(aIndex + 1, bIndex, longest),
                           GetLongest(aIndex, bIndex + 1, longest)));
    }
    
    return longestAtPos;
}

int main()
{
    string sep = "";
    
    while (getline(cin, a))
    {
        getline(cin, b);
        
        cout << sep;
        // Junk
        getline(cin, sep);
        sep = "\n";
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
                longestCommonSeq[i][j] = -1;
        
        int longest = 0;
        GetLongest(0, 0, longest);
        if (longest == 0)
            cout << "No common sequence.\n";
        else
        {
            set<string> longestSeqs;
            for (int i = 0; i < startOfLongest.size(); ++i)
            {
                longestSeqs.insert(a.substr(startOfLongest[i], longest));
            }
            
            for (set<string>::iterator iter = longestSeqs.begin(); iter != longestSeqs.end(); ++iter)
                cout << *iter << '\n';
        }
    }
}