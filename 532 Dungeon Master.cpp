#include <iostream>
#include <queue>

using namespace std;

int X, Y, Z;

bool Valid(int newX, int newY, int newZ)
{
    return newX >= 0 && newX < X && newY >= 0 && newY < Y && newZ >= 0 && newZ < Z;
}

struct Pos{
    Pos(int x, int y, int z)
        :x(x), y(y), z(z)
        {}
        
    int x, y, z;
};

// 0 if block, Inf otherwise
// [z][y][x]
int bestTime[35][35][35];
const int NumChanges = 6;
int xChange[] = {0, 0, -1, 1, 0, 0};
int yChange[] = {-1, 1, 0, 0, 0, 0};
int zChange[] = {0, 0, 0, 0, -1, 1};

int PushAlong(int xStart, int yStart, int zStart, int exitX, int exitY, int exitZ)
{  
    queue<Pos> frontier;
    frontier.push(Pos(xStart, yStart, zStart));
    
    while (!frontier.empty())
    {
        Pos current = frontier.front();
        frontier.pop();
        
        int nextTime = bestTime[current.z][current.y][current.x] + 1;
        for (int c = 0; c < NumChanges; ++c)
        {
            int newX = current.x + xChange[c];
            int newY = current.y + yChange[c];
            int newZ = current.z + zChange[c];
            
            if (Valid(newX, newY, newZ) && nextTime < bestTime[newZ][newY][newX])
            {
                if (newX == exitX && newY == exitY && newZ == exitZ)
                    return nextTime;
                
                bestTime[newZ][newY][newX] = nextTime;
                frontier.push(Pos(newX, newY, newZ));
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> Z >> Y >> X, Z)
    {
        const int size = Z * Y * X + 10;
        int startX, startY, startZ;
        int exitX=-1, exitY, exitZ;
        for (int z = 0; z < Z; ++z)
        {
            for (int y = 0; y < Y; ++y)
            {
                string line;
                cin >> line;
                for (int x = 0; x < X; ++x)
                {
                    if (line[x] == 'S')
                    {
                        startX = x;
                        startY = y;
                        startZ = z;
                        bestTime[z][y][x] = 0;
                    }
                    else if (line[x] == 'E')
                    {
                        exitX = x;
                        exitY = y;
                        exitZ = z;
                        bestTime[z][y][x] = size;
                    }
                    else if (line[x] == '.')
                        bestTime[z][y][x] = size;
                    else
                        bestTime[z][y][x] = 0;
                }
            }
        }
        
        int cost = PushAlong(startX, startY, startZ, exitX, exitY, exitZ);
        if (cost == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << cost << " minute(s)." << '\n';
    }
}