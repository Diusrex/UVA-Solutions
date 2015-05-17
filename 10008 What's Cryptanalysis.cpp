#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Letter
{
    Letter()
        : count(0)
    {}
    
    char letter;
    int count;
    
    bool operator<(const Letter & other) const
    {
        if (count != other.count)
            return count > other.count;
        
        return letter < other.letter;
    }
};

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    string line;
    vector<Letter> counts(26);
    for (int i = 0; i < 26; ++i)
        counts[i].letter = 'A' + i;
    
    while (N--)
    {
        getline(cin, line);
        for (int i = 0; i < line.size(); ++i)
        {
            int c = toupper(line[i]) - 'A';
            if (c >= 0 && c < 26)
                ++counts[c].count;
        }
    }
    
    sort(counts.begin(), counts.end());
    
    for (int i = 0; i < 26 && counts[i].count; ++i)
        cout << counts[i].letter << ' ' << counts[i].count << '\n';
}