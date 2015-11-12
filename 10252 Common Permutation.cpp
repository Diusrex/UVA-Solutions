#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    string a, b;
    while (getline(cin, a), getline(cin, b))
    {
        int aCounts[128], bCounts[128];
        for (int i = 'a'; i <= 'z'; ++i)
            aCounts[i] = bCounts[i] = 0;
        
        for (int i = 0; i < a.size(); ++i)
            ++aCounts[a[i]];
        
        for (int i = 0; i < b.size(); ++i)
            ++bCounts[b[i]];
        
        string longest = "";
        
        
        for (int i = 'a'; i <= 'z'; ++i)
            while (aCounts[i] > 0 && bCounts[i] > 0)
            {
                longest += (char) i;
                --aCounts[i];
                --bCounts[i];
            }
        
        cout << longest << '\n';
    }
}