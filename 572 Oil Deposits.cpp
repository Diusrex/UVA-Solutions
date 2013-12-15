#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Fill(const vector<string>& map, vector<vector<bool> >& checked, int currentx, int currenty, const int maxX, const int maxY)
{
    
    for (int xc = currentx - 1; xc < currentx + 2; ++xc)
    {
        for (int yc = currenty - 1; yc < currenty + 2; ++yc)
        {
            if (xc < maxX && xc >= 0 && yc < maxY && yc >= 0
                && !checked[xc][yc] && map[xc][yc] == '@')
            {
                checked[xc][yc] = true;
                Fill(map, checked, xc, yc, maxX, maxY);            
            }
        }
    }
}

int main()
{
    int m, n;
    
    cin >> m >> n;
    
    while (m != 0)
    {
        vector<string> map (m);
        vector<vector<bool> > checked(m, vector<bool>(n, false));
        
        for (int x = 0; x < m; ++x)
            cin >> map[x];
        
        int count(0);
        for (int x = 0; x < m; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                if (!checked[x][y] && map[x][y] == '@')
                {
                    checked[x][y] = true;
                    Fill(map, checked, x, y, m, n);
                    ++count;
                }
            }
        
        }
        
        cout << count << '\n';
        cin >> m >> n;
    }


}