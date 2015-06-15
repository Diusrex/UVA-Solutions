#include <iostream>
#include <string>

using namespace std;

const int UNKNOW = -1;

string first, second;
int longest[1234][1234];

int LongestSubseq(int firstPos, int secondPos)
{
    if (firstPos == first.size() || secondPos == second.size())
        return 0;
    
    int &best = longest[firstPos][secondPos];
    
    if (best == UNKNOW)
    {
        if (first[firstPos] == second[secondPos])
            best = 1 + LongestSubseq(firstPos + 1, secondPos + 1);
        else
            best = max(LongestSubseq(firstPos + 1, secondPos), 
                       LongestSubseq(firstPos, secondPos + 1));
    }
    
    return best;
}

int main()
{
    while (getline(cin, first) && getline(cin, second))
    {
        for (int i = 0; i < first.size(); ++i)
        {
            for (int j = 0; j < second.size(); ++j)
                longest[i][j] = UNKNOW;
        }
        
        cout << LongestSubseq(0, 0) << '\n';
    }
}