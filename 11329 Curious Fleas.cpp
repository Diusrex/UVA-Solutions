#include <iostream>
#include <set>
#include <queue>

using namespace std;

// Keep track of:
    // diceX 1-0 (length 2)
    // diceY 3-2 (length 2)
    // sides of die with ant 9-4 (length 6)
    // ants left on board 25-10 (length 16)
    // Uses total of 26 bit
    
   
typedef unsigned int Encoding;

const int Size = 4;

const int Invalid = 0;

const int PosAnd = Size - 1;
const int DieAnd = (1 << 6) - 1;

const int YPosBitShift = 2;
const int DieBitShift = 4;
const int BoardBitShift = 10;


// [left, down, up, right
int xShifts[4] = {-1, 0, 0, 1};
int yShifts[4] = {0, -1, 1, 0};

// Die bit orientation:
// 0 is bottom of die (on table)
// 1 is up
// 2 is right
// 3 is down
// 4 is left
// 5 is top of die (above table)
enum DF {DF_B, DF_U, DF_R, DF_D, DF_L, DF_T}; // DieFace
const int DieHasAllAnts = DieAnd;



int dieShiftFrom[6][4] =
    // Left Down  Up    Right
    {{DF_L, DF_D, DF_U, DF_R}, // DF_B
     {DF_U, DF_B, DF_T, DF_U}, // DF_U
     {DF_B, DF_R, DF_R, DF_T}, // DF_R
     {DF_D, DF_T, DF_B, DF_D}, // DF_D
     {DF_T, DF_L, DF_L, DF_B}, // DF_L
     {DF_R, DF_U, DF_D, DF_L}}; // DF_T
     
inline int Pos2DTo1D(int x, int y)
{
    return x * Size + y;
}

inline int GetDie(Encoding encoding)
{
    return (encoding >> DieBitShift) & DieAnd;
}



// Returns 0 if invalid
Encoding ApplyShift(const Encoding encoding, int shiftPos)
{
    Encoding x = (encoding & PosAnd) + xShifts[shiftPos];
    Encoding y = ((encoding >> YPosBitShift) & PosAnd) + yShifts[shiftPos];
    
    // Invalid, their value can't be stored in the encoding
    if ((x & PosAnd) != x || (y & PosAnd) != y)
        return Invalid;

    int posIn1D = Pos2DTo1D(x, y);
    
    
    Encoding previousDie = GetDie(encoding);
    Encoding newDie = 0;
    // Shift the die
    for (int face = 0; face < 6; ++face)
    {
        if (previousDie & (1 << (dieShiftFrom[face][shiftPos])))
            newDie |= (1 << face);
    }
    
    Encoding newBoard = (encoding >> BoardBitShift);
    
    const int dieBottomBit = 1 << DF_B;
    const int boardPositionBit = 1 << posIn1D;
    
    // The bottom of die already had a flea
    if (newDie & dieBottomBit)
    {
        // The board didn't have a 1
        if ((newBoard & boardPositionBit) == 0)
        {
            // Remove the flea from bottom of die
            newDie ^= dieBottomBit;
            newBoard |= boardPositionBit;
        }
    }
    
    // Board had a flea there
    else if (newBoard & boardPositionBit)
    {
        newDie |= dieBottomBit;
        newBoard ^= boardPositionBit;
    }
    
    return x | (y << YPosBitShift) | (newDie << DieBitShift) | (newBoard << BoardBitShift);
}

int GetMinimumMoves(Encoding start)
{
    set<Encoding> encountered;
    queue<Encoding> q;
    q.push(start);
    int count = 0;
    
    while (!q.empty())
    {
        queue<Encoding> nextQ;
        while (!q.empty())
        {
            Encoding current = q.front(); q.pop();
            if (encountered.find(current) != encountered.end())
                continue;
            
            encountered.insert(current);

            
            if (GetDie(current) == DieHasAllAnts)
                return count;
            
            for (int shift = 0; shift < 4; ++shift)
            {
                Encoding en = ApplyShift(current, shift);
                if (en != Invalid)
                    nextQ.push(en);
            }
        }
        
        
        swap(q, nextQ);
        ++count;
    }
    
    return -1;
}

int main()
{
    int T;
    cin >> T;
    
    string line;
    
    while (T--)
    {
        Encoding encoding = 0;
        
        for (int y = 0; y < Size; ++y)
        {
            cin >> line;
            for (int x = 0; x < Size; ++x)
            {
                if (line[x] == 'D')
                {
                    encoding |= x | (y << YPosBitShift);
                }
                
                else if (line[x] == 'X')
                {
                    encoding |= (1 << (BoardBitShift + Pos2DTo1D(x, y)));
                }
            }
        }
        
        int numMoves = GetMinimumMoves(encoding);
        
        if (numMoves == -1)
            cout << "impossible\n";
        else
            cout << numMoves << '\n';
    }
}