#include <cstdio>
#include <vector>

using namespace std;

struct pos
{
    pos(int x, int y)
        : x(x), y(y) {}
        
    int x, y;
};

const int xSize = 7, ySize = 7;

bool ValidMove(const vector<vector<bool> >& taken, const vector<vector<bool> >& available, int x, int y, int xChange, int yChange)
{
    if (y - yChange * 2 >= 0 && y - yChange * 2 < ySize) // yValid
    {
        if (x - xChange * 2 >= 0 && x - xChange * 2 < xSize) // xValid
        {
                // Middle                             // Start
            if (taken[y - yChange][x - xChange] && taken[y - yChange * 2][x - xChange * 2]) // May come from that direction
                return true;
        }
    }
    
    return false;
}


bool AbleToRecieve(vector<vector<bool> >& taken, const vector<vector<bool> >& available, int x, int y, pos & move)
{
    // The changes are in the opposite direction (where they came from). So the best is down (increasing y, then increase x, then decrease x, then decrease y)
    if (ValidMove(taken, available, x, y, 0, -1))
    {
        move = pos(0, -1);
        return true;
    }
    
    else if (ValidMove(taken, available, x, y, -1, 0))
    {
        move =  pos(-1, 0);
        return true;
    }
    
    else if (ValidMove(taken, available, x, y, 1, 0))
    {
        move = pos(1, 0);
        return true;
    }
    
    else if (ValidMove(taken, available, x, y, 0, 1))
    {
        move = pos(0, 1);
        return true;
    }
    
    return false;
}

bool MakeMove(vector<vector<bool> >& taken, const vector<vector<bool> >& available)
{
    pos bestTo(-1, -1), bestStart(-1, -1), bestMiddle(-1, -1);
    pos diff(-1, -1);
    
    for (int y = ySize - 1; y >= 0 && bestTo.x == -1; --y)
    {
        for (int x = xSize - 1; x >= 0; --x)
        {
            if (!taken[y][x] && available[y][x])
            {
                if (AbleToRecieve(taken, available, x, y, diff))
                {
                    bestTo = pos(x, y);
                    bestStart = pos(x - diff.x * 2, y - diff.y * 2);
                    bestMiddle = pos(x - diff.x, y - diff.y);
                    break;
                }
            }
        }
    }
    
    if (bestTo.x != -1)
    {
        taken[bestStart.y][bestStart.x] = taken[bestMiddle.y][bestMiddle.x] = false;
        taken[bestTo.y][bestTo.x] = true;
        return true;
    } 
    else
        return false;
}

int main()
{
    vector<vector<bool> > available(ySize, vector<bool>(xSize, true));
    
    vector<pos> convertedPos;
    vector<vector<int> > convertedScore(ySize, vector<int>(xSize, 0));
    
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if ((x < 2 || x > 4) && (y < 2 || y > 4))
                available[y][x] = false;
                
            else
            {
                convertedPos.push_back(pos(x, y));
                convertedScore[y][x] = convertedPos.size();
            }
        }
    }
    
    
    printf("HI Q OUTPUT\n");
    
    int T;
    scanf("%d", &T);

    while (T--)
    {
        vector<vector<bool> > taken(ySize, vector<bool>(xSize, false));
        
        int spotTaken;
        
        while (scanf("%d", &spotTaken), spotTaken--)
            taken[convertedPos[spotTaken].y][convertedPos[spotTaken].x] = true;
        
        while (MakeMove(taken, available));
            
        
        int score = 0;
        
        for (int y = 0; y < ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                if (taken[y][x])
                    score += convertedScore[y][x];
            }
        }
        
        printf("%d\n", score);
    }
    
    printf("END OF OUTPUT\n");
}