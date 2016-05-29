#include <iostream>
#include <queue>
#include <string>
#include <utility>

// Is c++ 11 due to use of queue.swap

using namespace std;

typedef pair<int, int> pos;

const int MaxSize = 1001;

int xSize, ySize;
bool passable[MaxSize][MaxSize];

const int NumChanges = 4;
int xChange[NumChanges] = {-1, 1, 0, 0};
int yChange[NumChanges] = {0, 0, -1, 1};

bool InGrid(int newX, int newY)
{
    return newX >= 0 && newX < xSize && newY >= 0 && newY < ySize;
}

int GetTime(queue<pos> &fire, queue<pos> &him)
{
    int turn = 1;
    while (!him.empty())
    {
        // Expand fire first
        queue<pos> tempQueue;
        while (!fire.empty())
        {
            pos next = fire.front(); fire.pop();
            for (int change = 0; change < NumChanges; ++change)
            {
                int x = next.first + xChange[change], y = next.second + yChange[change];
                if (InGrid(x, y) && passable[y][x])
                {
                    passable[y][x] = false;
                    tempQueue.push(make_pair(x, y));
                }
            }
        }
        
        fire.swap(tempQueue);
        
        while (!him.empty())
        {
            pos next = him.front(); him.pop();
            for (int change = 0; change < NumChanges; ++change)
            {
                int x = next.first + xChange[change], y = next.second + yChange[change];
                if (!InGrid(x, y))
                    return turn;
                
                if (passable[y][x])
                {
                    passable[y][x] = false;
                    tempQueue.push(make_pair(x, y));
                }
            }
        }
        
        him.swap(tempQueue);
        
        ++turn;
    }
    
    return -1;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> ySize >> xSize;
        queue<pos> fire, him;
        for (int y = 0; y < ySize; ++y)
        {
            string line;
            cin >> line;
            for (int x = 0; x < xSize; ++x)
            {
                passable[y][x] = false;
                if (line[x] ==  '.')
                    passable[y][x] = true;
                else if (line[x] == 'J')
                    him.push(make_pair(x, y));
                else if (line[x] == 'F')
                    fire.push(make_pair(x, y));
            }
            
        }
        
        int time = GetTime(fire, him);
        if (time == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << time << '\n';
    }   
}