#include <iostream>
#include <set>
#include <queue>

using namespace std;

struct State
{
    int x, y;
    
    bool operator<(const State& other) const
    {
        if (x != other.x)
            return x < other.x;
        
        return y < other.y;
    }
};

// Accessed by [y][x] & (1 << direction)
int directions[505][505];
set<State> encounteredStates[4];

// Are N, E, S, W
const int NumDir = 4;
int xChange[] = {0, 1, 0, -1};
int yChange[] = {-1, 0, 1, 0};

int X, Y;

int TimeToExit(const State& starting)
{
    queue<State> currentStates, nextTimestepStates;
    encounteredStates[0].insert(starting);
    currentStates.push(starting);
    int currentTimestep = 0;
    
    while (!currentStates.empty())
    {
        // This is the bit that must have been set for it to be able to travel to here.
        const int change = NumDir - currentTimestep % 4;
        State newState;
        int nextTimestepBucket = (currentTimestep + 1) % 4;
        while (!currentStates.empty())
        {
            const State current = currentStates.front();
            currentStates.pop();
            
            if (current.x + 1 == X && current.y + 1 == Y)
                return currentTimestep;
            
            for (int c = 0; c < NumDir; ++c)
            {
                if (directions[current.y][current.x] & (1 << ((c + change) % NumDir)))
                {
                    newState.x = current.x + xChange[c];
                    newState.y = current.y + yChange[c];
                    if (newState.x >= 0 && newState.x < X && newState.y >= 0 && newState.y < Y &&
                        encounteredStates[nextTimestepBucket].find(newState) == encounteredStates[nextTimestepBucket].end())
                    {
                        encounteredStates[nextTimestepBucket].insert(newState);
                        nextTimestepStates.push(newState);
                    }
                }
            }
        }
        
        ++currentTimestep;
        swap(currentStates, nextTimestepStates);
    }
    
    return -1;
}

int main()
{
    int toDirection[128];
    toDirection['N'] = 0;
    toDirection['E'] = 1;
    toDirection['S'] = 2;
    toDirection['W'] = 3;
    
    State start;
    start.x = 0; start.y = 0;
    while (cin >> Y >> X)
    {
        for (int y = 0; y < Y; ++y)
        {
            int highestX = X;
            if (y == Y - 1)
                highestX = X - 1;
            for (int x = 0; x < highestX; ++x)
            {
                string dirs;
                cin >> dirs;
                
                directions[y][x] = 0;
                for (int i = 0; i < dirs.size(); ++i)
                {
                    directions[y][x] |= (1 << toDirection[dirs[i]]);
                }
            }
            
        }
        
        for (int i = 0; i < 4; ++i)
            encounteredStates[i].clear();
        
        int time = TimeToExit(start);
        if (time != -1)
            cout << time << '\n';
        else
            cout << "no path to exit\n";
    }
}
