#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, n;
    
    cin >> T;
    
    string line, sep("");
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        cin >> n;
        
        vector<vector<int> > numBordering(n, vector<int>(n, 0));
        
        for (int y = 0; y < n; ++y)
        {
            cin >> line;
            
            for (int x = 0; x < n; ++x)
            {
                if (line[x] == '*')
                {
                    numBordering[y][x] = 10;
                    for (int xc = x - 1; xc < x + 2; ++xc)
                    {
                        if (xc >= 0 && xc < n)
                            for (int yc = y -1; yc < y + 2; ++yc)
                            {
                                if (yc >= 0 && yc < n)
                                    ++numBordering[yc][xc];
                            }
                    }
                }
            }
        }
        
        bool hitMine(false);
        
        for (int y = 0; y < n; ++y)
        {
            cin >> line;
            
            for (int x = 0; x < n; ++x)
            {
                if (line[x] == 'x')
                {
                    if (numBordering[y][x] >= 10)
                        hitMine = true;
                   
                }
                else if (numBordering[y][x] < 10)
                    numBordering[y][x] = -1;
            }
        }
        
        for (int y = 0; y < n; ++y)
        {    
            for (int x = 0; x < n; ++x)
            {
                if (numBordering[y][x] >= 0)
                {
                    if (numBordering[y][x] < 10)
                        cout << numBordering[y][x];
                    else if (hitMine)
                        cout << '*';
                    else
                        cout << '.';
                }
                else
                    cout << '.';
            }
            cout << '\n';
        }
    }
}