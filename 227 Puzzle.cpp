#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<char, int> xChange;
    map<char, int> yChange;
    
    xChange['A'] = 0;
    yChange['A'] = -1;
    
    xChange['B'] = 0;
    yChange['B'] = 1;
    
    xChange['R'] = 1;
    yChange['R'] = 0;
    
    xChange['L'] = -1;
    yChange['L'] = 0;
    
    
    // is [y][x]
    vector<string> grid(5);
    
    string lineBlank = "";
    for (int t = 1;; ++t)
    {
        
        
        int spaceX(-1), spaceY(-1);
        
        for (int y = 0; y < 5; ++y)
        {
            getline(cin, grid[y]);
            
            for (int x = 0; x < 5; ++x)
            {
                if (grid[y][x] == 'Z')
                    return 0;
                    
                if (grid[y][x] == ' ')
                {
                    spaceX = x;
                    spaceY = y;
                }
            }
        }
        
        cout << lineBlank;
        lineBlank = '\n';
        
        bool valid(true);
        
        char move;
        cin >> move;
            
        while (move != '0')
        {
            int newX(spaceX + xChange[move]), newY(spaceY + yChange[move]);
            
            if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5)
                valid = false;
                
            if (valid)
            {
                swap(grid[newY][newX], grid[spaceY][spaceX]);
                spaceX = newX;
                spaceY = newY;
            }
            
            cin >> move;
        }
        
        cout << "Puzzle #" << t << ":\n";
        
        if (valid)
        {
            for (int y = 0; y < 5; ++y)
            {
                string space = "";
                for (int x = 0; x < 5; ++x)
                {
                    cout << space << grid[y][x];
                    space = " ";
                }
                
                cout << '\n';
            }
        }
        
        else
            cout << "This puzzle has no final configuration.\n";
            
        cin.ignore();
    }
}