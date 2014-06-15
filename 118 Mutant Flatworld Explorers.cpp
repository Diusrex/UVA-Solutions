#include <iostream>
#include <vector>
#include <string>

using namespace std;

char directions[] = {'N', 'E', 'S', 'W'};
int xChange[] = {0, 1, 0, -1};
int yChange[] = {1, 0, -1, 0};


int main()
{
    int xSize, ySize;
    cin >> xSize >> ySize;
    
    vector<vector<bool> > scent(ySize + 1, vector<bool> (xSize + 1, false));
    
    int x, y;
    char startDirection;
    std::string orders;
    
    while (cin >> x >> y >> startDirection >> orders)
    {
        int direction;
        
        for (int i = 0; i < 4; ++i)
            if (startDirection == directions[i])
                direction = i;
        
        bool died = false;
        
       
        for (int i = 0; i < orders.size(); ++i)
        {
            
            if (orders[i] == 'R')
                direction = (direction + 1) % 4;
            
            else if (orders[i] == 'L')
                direction = (direction + 3) % 4;
            
            else
            {
                // Check if would take out of world
                if (x + xChange[direction] == -1 || x + xChange[direction] == xSize + 1 || y + yChange[direction] == -1 || y + yChange[direction] == ySize + 1)
                {
                    if (!scent[y][x])
                    {
                        scent[y][x] = died = true;
                        break;
                    }
                }
                
                else
                {
                    x += xChange[direction];
                    y += yChange[direction];
                }
            }
        }
        
        cout << x << ' ' << y << ' ' << directions[direction] << (died ? " LOST" : "") << '\n';
    }
}