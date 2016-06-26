#include <iostream>

using namespace std;

int N;
bool includedIn[26];
int after[26];

int order[22];

inline bool IncludesIndex(int index, int included)
{
    return (1 << index) & included;
}

void PrintOut(int index, int included)
{
    if (index == N)
    {
        for (int i = 0; i < N; ++i)
            cout << (char)('a' + order[i]);
        cout << '\n';
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (includedIn[i] && !IncludesIndex(i, included) && (after[i] & included) == after[i])
        {
            order[index] = i;
            PrintOut(index + 1, included | (1 << i));
        }
    }
}

int main()
{
    string line, sep = "";
    while (getline(cin, line))
    {
        cout << sep;
        sep = "\n";
        for (int i = 0; i < 26; ++i)
        {
            includedIn[i] = false;
            after[i] = 0;
        }
        N = 0;
        for (int i = 0; i < line.size(); i +=2)
        {
            includedIn[line[i] - 'a'] = true;
            ++N;
        }
        
        getline(cin, line);
        for (int i = 0; i < line.size(); i += 2)
        {
            int first = line[i] - 'a';
            i += 2;
            int second = line[i] - 'a';
            after[second] |= (1 << first);
        }
        
        PrintOut(0, 0);
    }
}