#include <iostream>
#include <set>

using namespace std;

struct Position
{
    int x, y;
    
    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
    
    bool operator<(const Position& other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

int NumP, CompletePiecesTaken;
Position pieces[8];
set<Position> invalidPositions;

// [piecesTaken][stepsLeft][y][x]
// Bigger than needed
bool tried[256][150][8][8];

int NumShift = 2;
int xShift[] = {2, 1};
int yShift[] = {1, 2};

bool Valid(const Position& pos)
{
    return pos.x >= 0 && pos.x < 8 && pos.y >= 0 && pos.y < 8;
}

bool Possible(int piecesTaken, int stepsLeft, const Position pos)
{
    if (invalidPositions.find(pos) != invalidPositions.end())
        return false;
    
    for (int i = 0; i < NumP; ++i)
        if (pieces[i] == pos)
            piecesTaken |= (1 << i);
    
    if (CompletePiecesTaken == piecesTaken)
        return true;
    
    if (stepsLeft == 0 || tried[piecesTaken][stepsLeft][pos.y][pos.x])
        return false;
    
    Position temp;
    
    for (int shift = 0; shift < NumShift; ++shift)
    {
        for (int xMult = -1; xMult <= 1; xMult += 2)
            for (int yMult = -1; yMult <= 1; yMult += 2)
            {
                temp.x = pos.x + xShift[shift] * xMult;
                temp.y = pos.y + yShift[shift] * yMult;
                if (Valid(temp) && Possible(piecesTaken, stepsLeft - 1, temp))
                    return true;
            }
    }
    
    tried[piecesTaken][stepsLeft][pos.y][pos.x] = true;
    
    return false;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int numMoves;
        cin >> numMoves;
        Position knight, temp;
        NumP = 0;
        invalidPositions.clear();
        
        string line;
        for (int y = 0; y < 8; ++y)
        {
            cin >> line;
            for (int x = 0; x < 8; ++x)
            {
                switch (line[x])
                {
                case 'k':
                    knight.x = x;
                    knight.y = y;
                    break;
                
                case 'P':
                    pieces[NumP].x = x;
                    pieces[NumP].y = y;
                    ++NumP;
                    break;
                
                case '.':
                    break;
                
                default:
                    temp.x = x;
                    temp.y = y;
                    invalidPositions.insert(temp);
                }
            }
        }
        
        CompletePiecesTaken = (1 << NumP) - 1;
        for (int i = 0; i < CompletePiecesTaken; ++i)
            for (int steps = 1; steps <= numMoves; ++steps)
                for (int y = 0; y < 8; ++y)
                    for (int x = 0; x < 8; ++x)
                        tried[i][steps][y][x] = false;
        
        
        if (Possible(0, numMoves, knight))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}