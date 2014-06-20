#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Check:
    // if O == X, that X has not won
    // if O + 1 == X, that O has not won

bool HasNotWon(const vector<string>& grid, char character)
{
    if (grid[0][0] == character && grid[0][1] == character && grid[0][2] == character)
        return false;
    
    if (grid[1][0] == character && grid[1][1] == character && grid[1][2] == character)
        return false;
        
    if (grid[2][0] == character && grid[2][1] == character && grid[2][2] == character)
        return false;
        
    if (grid[0][0] == character && grid[1][0] == character && grid[2][0] == character)
        return false;
    
    if (grid[0][1] == character && grid[1][1] == character && grid[2][1] == character)
        return false;
        
    if (grid[0][2] == character && grid[1][2] == character && grid[2][2] == character)
        return false;
        
    if (grid[0][0] == character && grid[1][1] == character && grid[2][2] == character)
        return false;
        
    if (grid[0][2] == character && grid[1][1] == character && grid[2][0] == character)
        return false;
    
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    vector<string> grid(3);
    
    while (T--)
    {
        int xCount = 0, oCount = 0;
        
        for (int i = 0; i < 3; ++i)
        {
            cin >> grid[i];
            for (int x = 0; x < 3; ++x)
            {
                if (grid[i][x] == 'X')
                    ++xCount;
                else if (grid[i][x] == 'O')
                    ++oCount;
            }
        }
        
        bool valid;
        
        if (xCount == oCount)
        {
            valid = HasNotWon(grid, 'X');
        }
        
        else if (xCount == oCount + 1)
        {
            valid = HasNotWon(grid, 'O');
        }
        
        else
            valid = false;
            
        if (valid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}