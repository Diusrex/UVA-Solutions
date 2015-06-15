#include <iostream>

using namespace std;

int main()
{
    int counts[128];
    
    string line;
    
    int diff = 'a' - 'A';
    
    while (getline(cin, line))
    {
        for (int i = 'A'; i <= 'z'; ++i)
            counts[i] = 0;
        
        for (int i = 0; i < line.size(); ++i)
            ++counts[line[i]];
        
        int highest = 0;
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (counts[i] > highest)
                highest = counts[i];
            
            if (counts[i + diff] > highest)
                highest = counts[i + diff];
        }
        
        for (int i = 'A'; i <= 'Z'; ++i)
            if (counts[i] == highest)
                cout << (char) i;
        
        for (int i = 'a'; i <= 'z'; ++i)
            if (counts[i] == highest)
                cout << (char) i;
            
        cout << ' ' << highest << '\n';
    }
}