#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int R, C;
vector<vector<bool> > passable;
vector<vector<int> > counts;


int cShift[4] = {1, 0, -1, 0};
int rShift[4] = {0, 1, 0, -1};

inline bool IsPassable(int r, int c, int shift)
{
    int newR = r + rShift[shift], newC = c + cShift[shift];
    
    return newR >= 0 && newR < R && newC >= 0 && newC < C
        && passable[newR][newC];
}


int main()
{
    
    while (cin >> R >> C, R)
    {
        passable.assign(R, vector<bool>(C, false));
        counts.assign(R, vector<int>(C, 0));
        
        string line;
        for (int r = 0; r < R; ++r)
        {
            cin >> line;
            for (int c = 0; c < C; ++c)
                if (line[c] == '0')
                    passable[r][c] = true;
        }
        
        int r = R - 1, c = 0, dir = 0;
        
        do {
            // Had nothing to its right, so would follow the wall
            if (IsPassable(r, c, (dir + 1) % 4))
            {
                dir = (dir + 1) % 4;
            }
            
            // While there is something infront of it, try to left
            while (!IsPassable(r, c, dir))
            {
                dir = (dir + 3) % 4;
            }
            
            r += rShift[dir];
            c += cShift[dir];
            
            
            
            counts[r][c]++;
        } while (r != R - 1 || c != 0);
        
        int occur[5] = {0};
        
        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                if (counts[r][c] <= 4 && passable[r][c])
                    occur[counts[r][c]]++;
            }
        }
        
        for (int i = 0; i <= 4; ++i)
            cout << setw(3) << occur[i];
        cout << '\n';
    }
    
}