#include <iostream>
#include <map>
#include <string>

using namespace std;

const int GridSize = 4;
const int NumElements = GridSize * GridSize;
const int UNFORCED = -1;

enum Owner {UNOWNED, X, O};

struct Board {
    Owner grid[NumElements];
    bool xTurn;
    
    const Owner& operator[](int x) const
    {
        return grid[x];
    }
    
    Owner& operator[](int x)
    {
        return grid[x];
    }
    
    bool operator<(const Board& other) const {
        for (int i = 0; i < NumElements; ++i)
            if (grid[i] != other.grid[i])
                return grid[i] < other.grid[i];
            
        return false;
    }
};

// This doesn't need to be cleared at all
map<Board, int> oForcedToLosePlay;

Owner Winner(const Board& board)
{
    // Horizontal
    for (int start = 0; start < NumElements; start += GridSize)
    {
        if (board[start] == UNOWNED)
            continue;
        bool same = true;
        for (int i = 1; i < GridSize; ++i)
            if (board[start + i] != board[start])
                same = false;
        
        if (same)
            return board[start];
    }
    
    // Vertical
    for (int start = 0; start < GridSize; ++start)
    {
        if (board[start] == UNOWNED)
            continue;
        bool same = true;
        for (int i = GridSize; i < NumElements; i += GridSize)
            if (board[start + i] != board[start])
                same = false;
        
        if (same)
            return board[start];
    }
    
    // One diagonal
    if (board[0] != UNOWNED && board[0] == board[5] && board[5] == board[10] && board[10] == board[15])
        return board[0];
    
    if (board[3] != UNOWNED && board[3] == board[6] && board[6] == board[9] && board[9] == board[12])
        return board[3];
    
    return UNOWNED;
}

int OForcedToLose(Board& board)
{
    if (oForcedToLosePlay.find(board) == oForcedToLosePlay.end())
    {
        int forcedToLosePlayCurrent = UNFORCED;
        
        // Check if there is a winner
        Owner winner = Winner(board);
        if (winner != UNOWNED)
        {
            forcedToLosePlayCurrent = (winner == X ? 0 : UNFORCED);
        }
        else
        {
            bool allForced = true;
            for (int i = 0; i < NumElements; ++i)
            {
                if (board.grid[i] == UNOWNED)
                {
                    board.grid[i] = (board.xTurn ? X : O);
                    board.xTurn = !board.xTurn;
                    
                    int winPlay = OForcedToLose(board);
                    allForced &= (winPlay != UNFORCED);
                    
                    board.grid[i] = UNOWNED;
                    board.xTurn = !board.xTurn;
                    
                    if (board.xTurn && winPlay != UNFORCED)
                    {
                        forcedToLosePlayCurrent = i;
                        break;
                    }
                    
                    if (!board.xTurn && !allForced)
                        break;
                }
            }
            
            // o is only forced if all of the moves would result in it being forced
            if (allForced && !board.xTurn)
                forcedToLosePlayCurrent = 0;
        }
        
        return oForcedToLosePlay[board] = forcedToLosePlayCurrent;
    }
    
    return oForcedToLosePlay[board];
}

int main()
{
    char id;
    Board board;
    // Since all will have X be first
    board.xTurn = true;
    while (cin >> id, id != '$')
    {
        for (int y = 0; y < GridSize; ++y)
        {
            string line;
            cin >> line;
            for (int x = 0; x < GridSize; ++x)
            {
                int index = y * GridSize + x;
                switch (line[x])
                {
                case '.':
                    board.grid[index] = UNOWNED;
                    break;
                case 'o':
                    board.grid[index] = O;
                    break;
                case 'x':
                    board.grid[index] = X;
                    break;
                }
            }
        }
        
        int forcedPos = OForcedToLose(board);
        if (forcedPos == UNFORCED)
            cout << "#####\n";
        else
            cout << "(" << (forcedPos / GridSize) << ',' << (forcedPos % GridSize) << ")\n";
    }
}