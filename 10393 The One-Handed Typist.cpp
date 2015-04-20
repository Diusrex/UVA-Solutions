#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool fingerAvailable[15];
int fingerRequired[128];

void SetUp()
{
    fingerRequired['q'] = fingerRequired['a'] = fingerRequired['z'] = 1;
    fingerRequired['w'] = fingerRequired['s'] = fingerRequired['x'] = 2;
    fingerRequired['e'] = fingerRequired['d'] = fingerRequired['c'] = 3;
    
    fingerRequired['r'] = fingerRequired['f'] = fingerRequired['v'] = 
        fingerRequired['t'] = fingerRequired['g'] = fingerRequired['b'] = 4;
   
    fingerRequired['y'] = fingerRequired['h'] = fingerRequired['n'] = 
        fingerRequired['u'] = fingerRequired['j'] = fingerRequired['m'] = 7;
        
    fingerRequired['i'] = fingerRequired['k'] = 8;
    
    fingerRequired['o'] = fingerRequired['l'] = 9;
    
    fingerRequired['p'] = 10;
}

bool Possible(const string &str)
{
    for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        if (!fingerAvailable[fingerRequired[*iter]])
            return false;
    }
    
    return true;
}

int main()
{
    SetUp();
    
    int F, N;
    
    while (cin >> F >> N)
    {
        for (int i = 1; i <= 10; ++i)
            fingerAvailable[i] = true;
        
        while (F--)
        {
            int cF;
            cin >> cF;
            fingerAvailable[cF] = false;
        }
        
        int bestLength = 0;
        set<string> longestWords;
        string current;
        
        while (N--)
        {
            cin >> current;
            
            if (current.size() > bestLength && Possible(current))
            {
                bestLength = current.size();
                longestWords.clear();
                longestWords.insert(current);
            }
            else if (current.size() == bestLength && Possible(current))
                longestWords.insert(current);
        }
        vector<string> best(longestWords.begin(), longestWords.end());
        sort(best.begin(), best.end());
            
        cout << best.size() << '\n';
        for (int i = 0; i < best.size(); ++i)
            cout << best[i] << '\n';
    }
}