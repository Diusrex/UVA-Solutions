#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

// How will solve:
    // Only care about actual pushes, not moves
    // So, will do a dfs to find all possible pushes that can be done, and try each push
    // Will move the player into where it was, decrement the counter, and do dfs search on this
    // Very similar, but recursion will be different
    
int height, width, boardSize; // width should be set to the max width for all of the lines
bool walkable[256]; // Converted to 1d array

class BoardState
{
public:
    BoardState()
        : oneDPosition(0)
    {
        for (int i = 0; i < 4; ++i)
            boxPositions[i] = 0;
    }
    
    void SetOneDPos(int newPos)
    {
        oneDPosition = newPos;
    }
    
    bool HasBox(int oneDPos) const
    {
        int box = GetUsedBoxPosition(oneDPos);
        return boxPositions[box] & (1LL << GetBoxPositionOffset(oneDPos));
    }
    
    void MarkPosition(int oneDPos)
    {
        int box = GetUsedBoxPosition(oneDPos);
        boxPositions[box] ^= (1LL << GetBoxPositionOffset(oneDPos));
    }
    
    void MoveBox(int oldPos, int newPos)
    {
        MarkPosition(oldPos);
        MarkPosition(newPos);
    }
    
    int inline GetUsedBoxPosition(int oneDPos) const
    {
        return oneDPos / 64;
    }
    
    int inline GetBoxPositionOffset(int oneDPos) const
    {
        return oneDPos % 64;
    }

    // Will test for if it meets the final requirement
    bool IsMatch(const BoardState & other) const
    {
        for (int i = 0; i < 4; ++i)
        {
            if (boxPositions[i] != other.boxPositions[i])
                return false;
        }
        
        return true;
    }
    
    bool operator<(const BoardState & other) const
    {
        if (oneDPosition != other.oneDPosition)
            return oneDPosition < other.oneDPosition;
       
        for (int i = 0; i < 4; ++i)
        {
            if (boxPositions[i] != other.boxPositions[i])
                return boxPositions[i] < other.boxPositions[i];
        }
        
        return false;
    }
    
    int oneDPosition;
private:
    // Don't use bitset because it will not allow comparison when in set
    unsigned long long boxPositions[4];
};

// Going from 2d to 1d will be [x + y * width]
inline int ConvertTo1DPosition(int x, int y)
{
    return x + y * width;
}

void PrintOut(const BoardState &currentState)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
            cout << currentState.HasBox(ConvertTo1DPosition(x, y));
        cout << '\n';
    }
    cout << '\n';
}

void SetUpBoardStatesAndWalkableGrid(const vector<string> &grid, BoardState &initialState, BoardState &goalState)
{
    for (int y = 0; y < height; ++y)
    {
        // Grid[y].size may be smaller than width
        for (int x = 0; x < grid[y].size(); ++x)
        {
            switch (grid[y][x])
            {
                case '$':
                    initialState.MarkPosition(ConvertTo1DPosition(x, y));
                    break;
                
                case '.':
                    goalState.MarkPosition(ConvertTo1DPosition(x, y));
                    break;
                    
                case '*':
                    initialState.MarkPosition(ConvertTo1DPosition(x, y));
                    goalState.MarkPosition(ConvertTo1DPosition(x, y));
                    break;
                
                case '+':
                    goalState.MarkPosition(ConvertTo1DPosition(x, y));
                    // Want to fall through
                case '@':
                    initialState.SetOneDPos(ConvertTo1DPosition(x, y));
                    break;
            }
            
            walkable[ConvertTo1DPosition(x, y)] = (grid[y][x] != '#');
        }
    }
}

inline bool StaysInBounds(int newOneDPos, int oldOneDPos)
{
    return newOneDPos >= 0 && newOneDPos < boardSize // Leaves valid boundaries
        && walkable[newOneDPos]
        && (newOneDPos % width == oldOneDPos % width // Stayed on same row
            || newOneDPos / width == oldOneDPos / width); // Stayed on same column;
}

const int NUM_MOVES = 4;
int oneDChanges[NUM_MOVES] = {-1, -width, width, 1};
// WARNING: This must be called
inline void UpdateMovesBeforeRun()
{
    oneDChanges[2] = width;
    oneDChanges[1] = - width;
}

bool IsPossibleToReach(const BoardState &currentState, const BoardState &goalState, map<BoardState, int> &allReachedStates, int K);




bool DFSToFindMoves(int oneDPos, const BoardState &currentState, const BoardState &goalState, map<BoardState, int> &allReachedStates, int K, bitset<256> &visitedSpots)
{
    visitedSpots[oneDPos] = true;
    for (int i = 0; i < NUM_MOVES; ++i)
    {
        int newPos = oneDPos + oneDChanges[i];
        if (StaysInBounds(newPos, oneDPos) && !visitedSpots[newPos])
        {
            // If there is a box, try to move it
            if (currentState.HasBox(newPos))
            {
                int furtherSpot = newPos + oneDChanges[i];
                if (StaysInBounds(furtherSpot, newPos) && !currentState.HasBox(furtherSpot))
                {
                    BoardState newState = currentState;
                    newState.SetOneDPos(newPos);
                    newState.MoveBox(newPos, furtherSpot);
                    
                    if (IsPossibleToReach(newState, goalState, allReachedStates, K - 1))
                    {
                        //cout << "Moving from " << oneDPos << " to " << newPos << ' ' << furtherSpot << '\n';
                        //PrintOut(currentState);
                        return true;
                    }
                }
            }
            else if (DFSToFindMoves(newPos, currentState, goalState, allReachedStates, K, visitedSpots))
                return true;
        }
    }
    
    return false;
}

bool IsPossibleToReach(const BoardState &currentState, const BoardState &goalState, map<BoardState, int> &allReachedStates, int K)
{
    if (currentState.IsMatch(goalState))
        return true;
    if (K == 0)
        return false;
    
    map<BoardState, int>::iterator iter = allReachedStates.find(currentState);
    // Has been reached earlier
    if (allReachedStates[currentState] >= K)
        return false;
    
    allReachedStates[currentState] = K;
    
    bitset<256> visitedSpots;
    
    return DFSToFindMoves(currentState.oneDPosition, currentState, goalState, allReachedStates, K, visitedSpots);
}

int main()
{
    int K;
    
    while (cin >> K)
    {
        cin.ignore();
        string line;
        vector<string> grid;
        
        width = 0;
        while (getline(cin, line) && line != "")
        {
            grid.push_back(line);
            width = max(width, (int)line.size());
        }
        
        height = grid.size();
        boardSize = ConvertTo1DPosition(width, height);
        UpdateMovesBeforeRun();
        
        BoardState initialState, goalState;
        SetUpBoardStatesAndWalkableGrid(grid, initialState, goalState);
        
        map<BoardState, int> allReachedStates;
        
        cout << (IsPossibleToReach(initialState, goalState, allReachedStates, K) ? "YES\n" : "NO\n");
    }
}
