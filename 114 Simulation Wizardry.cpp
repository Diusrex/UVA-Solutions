#include <iostream>

using namespace std;

// Note: Reduce all positions by 1

const int NumMoves = 4;
int xChange[] = {1, 0, -1, 0};
int yChange[] = {0, 1, 0, -1};

const int MaxGridSize = 52;

// All are indexed [y][x]
bool hasBumper[MaxGridSize][MaxGridSize];
int bumperCost[MaxGridSize][MaxGridSize];
int bumperScore[MaxGridSize][MaxGridSize];


int main()
{
    int X, Y;
    cin >> X >> Y;
    int wallCost, numBumper;
    cin >> wallCost >> numBumper;

    for (int y = 0; y < Y; ++y)
    {
        for (int x  = 0; x < X; ++x)
            hasBumper[y][x] = false;
    }

    while (numBumper--)
    {
        int x, y;
        cin >> x >> y;
        --x; --y;
        hasBumper[y][x] = true;
        cin >> bumperScore[y][x] >> bumperCost[y][x];
    }
    int overallScore = 0;
    
    int ballX, ballY, dir, lifetime;
    while (cin >> ballX >> ballY >> dir >> lifetime)
    {
        int score = 0;
        --ballX; --ballY;
        while (--lifetime > 0)
        {
            int newX = ballX + xChange[dir], newY = ballY + yChange[dir];
            // Hits wall
            //cout << "From " << ballX << ' ' << ballY << " attempting " << newX << ' ' << newY << " with " << lifetime << '\n';
            if (newX <= 0 || newX >= X - 1 || newY <= 0 || newY >= Y - 1)
            {
                //cout << "Hit wall\n";
                lifetime -= wallCost;
                dir = (dir + 3) % NumMoves;
            }
            else if (hasBumper[newY][newX])
            {
                //cout << "Hit bumper\n";
                lifetime -= bumperCost[newY][newX];
                score += bumperScore[newY][newX];
                dir = (dir + 3) % NumMoves;
            }
            else
            {
                //cout << "Moved\n";
                ballX = newX;
                ballY = newY;
            }
        }
        
        cout << score << '\n';
        overallScore += score;
    }
    
    cout << overallScore << '\n';
}
