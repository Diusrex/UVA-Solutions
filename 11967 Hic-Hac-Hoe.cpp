#include <iostream>
#include <set>
#include <map>
#include <iterator>

// Main trick:
    // Overflow of numbers

using namespace std;

struct Play
{
    Play(int pos, int owner)
        : pos(pos),
        owner(owner)
    {}
    
    int pos, owner;
    
    bool operator<(const Play & other) const
    {
        return pos < other.pos;
    }
};

int K;

bool TryOut(map<long long, set<Play> >& dir, long long firstIndex, int secondIndex, int player)
{
    set<Play> &usedSet = dir[firstIndex];
    
    set<Play>::iterator setIter = usedSet.insert(Play(secondIndex, player)).first;
    
    // Count is the # of elements to the left and right of this element
    int count = 1;
    
    // Look forward, then backward
    set<Play>::iterator iter = setIter;
    ++iter;
    for (int wanted = secondIndex + 1; iter != usedSet.end() && count < K; ++iter, ++wanted, ++count)
    {
        if (iter->pos != wanted || iter->owner != player)
            break;
    }
    
    if (count >= K)
        return true;
    
    iter = setIter;
    if (iter == usedSet.begin())
        return false;
    --iter;
    
    for (int wanted = secondIndex - 1; count < K; --iter, --wanted, ++count)
    {
        if (iter->pos != wanted || iter->owner != player)
            break;
        if (iter == usedSet.begin())
        {
            if (count + 1 == K)
                return true;
            return false;
        }
    }
    
    return count == K;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        // Horizontal is [y][x], vertical is [x][y], downwardDiagonal is [x + y][y], upwardDiagonal is[x - y][y]
        map<long long, set<Play> > horizontal, vertical, downwardDiagonal, upwardDiagonal;
        
        int n;
        cin >> n >> K;
        
        int player = 0;
        bool winner[2] = {false, false};
        while (n--)
        {
            long long x, y;
            cin >> x >> y;
            
            // No need to update if the player has already won
            if (!winner[player])
            {
                winner[player] |= TryOut(horizontal, y, x, player);
                winner[player] |= TryOut(vertical, x, y, player);
                winner[player] |= TryOut(downwardDiagonal, x + y, y, player);
                winner[player] |= TryOut(upwardDiagonal, x - y, y, player);
            }
            
            player = 1 - player;
        }
        
        if (winner[0] && winner[1])
            cout << "Case " << t << ": error\n";
        else if (winner[0])
            cout << "Case " << t << ": crosses\n";
        else if (winner[1])
            cout << "Case " << t << ": noughts\n";
        else
            cout << "Case " << t << ": none\n";
    }
}