#include <iostream>
#include <vector>
#include <sstream>
#include <ctype.h>

// Diagonal cells are considered to be adjacent.

using namespace std;
vector<string> grid;
int rCount, cCount;

int rC[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int cC[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int fill(int r, int c, const char &toSwitchFrom, const char &toSwitchTo)
{
    if (r < 0 || r >= rCount || c < 0 || c >= cCount
        || grid[r][c] != toSwitchFrom)
        return 0;
    
    grid[r][c] = toSwitchTo;
    int s = 1;
    for (int i = 0; i < 8; ++i)
        s += fill(r + rC[i], c + cC[i], toSwitchFrom, toSwitchTo);
    
    return s;
}

int main()
{
    int T;
    cin >> T >> ws;
    
    int baseVal = 'X' + 'W';
    
    string sep = "";
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        grid.clear();
        
        string line;
        
        while (isalpha(cin.peek()))
        {
            cin >> line >> ws;
            grid.push_back(line);
        }
        
        rCount = grid.size();
        cCount = grid[0].size();
        
        int first, second;
        
        while (isdigit(cin.peek()))
        {
            cin >> first >> second >> ws;
            --first;
            --second;
            char toSwitchFrom = grid[first][second];
            char toSwitchTo = baseVal - toSwitchFrom;
            
            cout << fill(first, second, toSwitchFrom, toSwitchTo) << '\n';
        }
        
        cin >> ws;
    }
}