#include <iostream>
#include <string>

using namespace std;

const int NumPebbles = 12;
const int NumConfigurations = (2 << NumPebbles) + 5;
int saved[NumConfigurations];

inline bool HasPebble(int pos, int board)
{
    return board & (1 << pos);
}

int GetNumPebbles(int board)
{
    int count = 0;
    while (board)
    {
        count += (board & 1);
        board >>= 1;
    }
    
    return count;
}

int GetMin(int board)
{
    int &best = saved[board];
    
    if (best == -1)
    {
        best = GetNumPebbles(board);
        // Shift to the left
        for (int i = 2; i < NumPebbles; ++i)
        {
            if (HasPebble(i, board) && HasPebble(i - 1, board) && !HasPebble(i - 2, board))
            {
                int newBoard = board ^ (1 << i) ^ (1 << (i - 1)) ^ (1 << (i - 2));
                best = min(best, GetMin(newBoard));
            }
        }
        
        // Shift to the right
        for (int i = NumPebbles - 3; i >= 0; --i)
        {
            if (HasPebble(i, board) && HasPebble(i + 1, board) && !HasPebble(i + 2, board))
            {
                int newBoard = board ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i + 2));
                best = min(best, GetMin(newBoard));
            }
        }
    }
    
    return best;
}

int main()
{
    int T;
    cin >> T;
    
    // Only need to reset once
    for (int i = 0; i < NumConfigurations; ++i)
        saved[i] = -1;
        
    while (T--)
    {
        string board;
        cin >> board;
        
        int encoded = 0;
        for (int i = 0; i < NumPebbles; ++i)
            if (board[i] == 'o')
                encoded |= (1 << i);
        
        cout << GetMin(encoded) << '\n';
    }
}