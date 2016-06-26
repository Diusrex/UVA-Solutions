#include <iostream>
#include <string>

using namespace std;

int X, Y;
// Is, like usual [y][x]
string grid[9];

const int NumMoves = 3;
const int xMoves[] = {-1, 0, 1};
const int yMoves[] = {0, -1, 0};
const string moveNames[] = {"left", "forth", "right"};

string output[7];
const string Needed = "IEHOVA#";

bool GetToIt(int x, int y, int pos)
{
    if (grid[y][x] == '#')
    {
        cout << output[0];
        for (int i = 1; i < pos; ++i)
            cout << ' ' << output[i];
        cout << '\n';
        return true;
    }
    else if (pos == Needed.size())
        return false;
    
    for (int move = 0; move < NumMoves; ++move)
    {
        int newX = x + xMoves[move], newY = y + yMoves[move];
        if (newX >= 0 && newX < X && newY >= 0 && newY < Y
            && grid[newY][newX] == Needed[pos])
        {
            // Try moving there
            output[pos] = moveNames[move];
            if (GetToIt(newX, newY, pos + 1))
                return true;
        }
            
    }
    
    return false;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> Y >> X;
        int hisX, hisY;
        for (int y = 0; y < Y; ++y)
        {
            cin >> grid[y];
            for (int x = 0; x < X; ++x)
                if (grid[y][x] == '@')
                {
                    hisX = x;
                    hisY = y;
                }
        }
        
        GetToIt(hisX, hisY, 0);
    }
}