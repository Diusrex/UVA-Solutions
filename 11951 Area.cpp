#include <iostream>
#include <cmath>

using namespace std;

// To avoid needing to reset all gridCost will calculate
// In horizontal lines from a given starting point.
// That way, the recurrence will know that CalculateCost has already been
// called.

int squareCost[105][105];
int gridCost[105][105][105][105];

// Must be called after CalculateCost
int GetCost(int xTop, int yTop, int xBottom, int yBottom)
{
    // Went outside
    if (xTop > xBottom || yTop > yBottom)
    {
        return 0;
    }
    
    else if (xTop == xBottom && yTop == yBottom)
        return squareCost[yTop][xTop];
    
    return gridCost[yTop][xTop][yBottom][xBottom];
}

int CalculateCost(int xTop, int yTop, int xBottom, int yBottom)
{
    return gridCost[yTop][xTop][yBottom][xBottom] =
               GetCost(xTop, yTop, xBottom, yBottom - 1)
             + GetCost(xTop, yTop, xBottom - 1, yBottom)
             - GetCost(xTop, yTop, xBottom - 1, yBottom - 1)
             + squareCost[yBottom][xBottom];
}


int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int R, C, K;
        cin >> R >> C >> K;
        
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                cin >> squareCost[r][c];
        
        int bestArea = 0, bestCost = 0;
        
        for (int startR = 0; startR < R; ++startR)
        {
            int max_height = R - startR;
            // Gone too far down
            if (max_height * C < bestArea)
                break;
            for (int startC = 0; startC < C; ++startC)
            {
                int max_width = C - startC;
                // Gone too far along C for this row to beat max size
                if (max_width * max_height < bestArea)
                    break;
                // No point in trying if it is higher than cost can already afford.
                int baseCost = squareCost[startR][startC];

                if (baseCost > K)
                    continue;
                
                for (int endR = startR; endR < R; ++endR)
                {
                    int height = endR - startR + 1;
                    
                    // No idea why it will be incorrect if I allow this.
                    // Need to go further down to have a chance
                    //if (height * max_width < bestArea)
                    //    continue;
                
                    // No point in trying to go lower if it is higher than cost can already afford.
                    baseCost = CalculateCost(startC, startR, startC, endR);
                    if (baseCost > K)
                        break;
                    
                    for (int endC = startC; endC < C; ++endC)
                    {
                        int cost = CalculateCost(startC, startR, endC, endR);
                        int area = (endC - startC + 1) * height;
                        
                        // No point in trying farther
                        if (cost > K)
                            break;
                        if (area > bestArea)
                        {
                            bestArea = area;
                            bestCost = cost;
                        }
                        else if (area == bestArea)
                            bestCost = min(bestCost, cost);
                    }
                }
            }
        }
        
        cout << "Case #" << t << ": " << bestArea << ' ' << bestCost << '\n';
    }
}