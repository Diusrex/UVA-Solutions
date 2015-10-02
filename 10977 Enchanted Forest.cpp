#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Point
{
    Point()
        : r(0),
        c(0)
    {}
    
    Point(int r, int c, int d)
        : r(r),
        c(c),
        d(d)
    {}
    
    int r, c, d;
};

int R, C;

// When enter spot, make it impassable
// Will have outer edge be impassable
bool passable[206][206];

int rChange[] = {0, -1, 1, 0};
int cChange[] = {-1, 0, 0, 1};

int GetBestPathCostToEnd()
{
    if (!passable[1][1])
        return -1;
    
    if (R == 1 && C == 1)
        return 0;
    
    queue<Point> points;
    
    points.push(Point(1, 1, 0));
    passable[1][1] = false;
    
    
    while (!points.empty())
    {
        Point point = points.front(); points.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            int nR = point.r + rChange[i], nC = point.c + cChange[i];
            
            if (passable[nR][nC])
            {
                if (nR == R && nC == C)
                    return point.d + 1;
                passable[nR][nC] = false;
                points.push(Point(nR, nC, point.d + 1));
            }
        }
    }
    
    return -1;
}

int main()
{
    
    while (cin >> R >> C, R)
    {
        for (int r = 1; r <= R; ++r)
        {
            passable[r][0] = false;
            passable[r][C + 1] = false;
            for (int c = 1; c <= C; ++c)
                passable[r][c] = true;
        }
        for (int c = 0; c <= C; ++c)
        {
            passable[0][c] = false;
            passable[R + 1][c] = false;
        }
        
        int m;
        cin >> m;
        
        while (m--)
        {
            int r, c;
            cin >> r >> c;
            passable[r][c] = false;
        }
        
        int n;
        cin >> n;
        
        while (n--)
        {
            int r, c, l;
            cin >> r >> c >> l;
            
            int farthest = l * l;
            
            for (int rC = -l; rC <= l; ++rC)
            {
                for (int cC = -l; cC <= l; ++cC)
                {
                    if (cC * cC + rC * rC > farthest)
                        continue;
                    
                    int rNew = r + rC, cNew = c + cC;
                    if (rNew > 0 && cNew > 0 && rNew <= R && cNew <= C)
                        passable[rNew][cNew] = false;
                }
            }
        }
        
        int cost = GetBestPathCostToEnd();
        if (cost == -1)
            cout << "Impossible.\n";
        else
            cout << cost << '\n';
    }
}