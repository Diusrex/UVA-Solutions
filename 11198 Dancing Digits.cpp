#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

const int Count = 8;

bool isMale[Count];
bool isPrime[16];


// 8^8 has only 16,777,216 different combinations

struct Order
{
    int numbers[8];
    
    bool operator<(const Order& other) const
    {
        for (int i = 0; i < Count; ++i)
            if (numbers[i] != other.numbers[i])
                return numbers[i] < other.numbers[i];
            
        return false;
    }
};

inline bool MayDance(Order current, int first, int second)
{
    int a = current.numbers[first], b = current.numbers[second];
    return isMale[a] != isMale[b] && isPrime[abs(a) + abs(b)];
}

set<Order> allOrdersReached;

void TryToAdd(const Order& order, queue<Order>& addTo)
{
    if (allOrdersReached.find(order) != allOrdersReached.end())
        return;
    
    allOrdersReached.insert(order);
    addTo.push(order);
}

// Will do bfs
int GetNumMoves(const Order& startingOrder)
{
    queue<Order> currentOrders;
    currentOrders.push(startingOrder);
    allOrdersReached.insert(startingOrder);
    queue<Order> nextDepthOrders;
    int currentDepth = 0;
    
    while (!currentOrders.empty())
    {
        while (!currentOrders.empty())
        {
            const Order current = currentOrders.front();
            currentOrders.pop();
            bool inOrder = true;
            for (int i = 0; i < 8; ++i)
                if (current.numbers[i] != i + 1)
                    inOrder = false;
            if (inOrder)
                return currentDepth;
            
            Order switchedUp;
            
            for (int first = 0; first < 8; ++first)
            {
                for (int second = first + 1; second < 8; ++second)
                    if (MayDance(current, first, second))
                    {
                        for (int i = 0; i < first; ++i)
                            switchedUp.numbers[i] = current.numbers[i];
                        for (int i = second + 1; i < 8; ++i)
                            switchedUp.numbers[i] = current.numbers[i];
                        
                        // Move first to second
                        for (int i = first; i < second - 1; ++i)
                            switchedUp.numbers[i] = current.numbers[i + 1];
                        // Before
                        switchedUp.numbers[second - 1] = current.numbers[first];
                        switchedUp.numbers[second] = current.numbers[second];
                        TryToAdd(switchedUp, nextDepthOrders);
                        // After
                        swap(switchedUp.numbers[second - 1], switchedUp.numbers[second]);
                        TryToAdd(switchedUp, nextDepthOrders);
                        
                        // Move second to first
                        for (int i = second; i > first + 1; --i)
                            switchedUp.numbers[i] = current.numbers[i - 1];
                        // After
                        switchedUp.numbers[first + 1] = current.numbers[second];
                        switchedUp.numbers[first] = current.numbers[first];
                        TryToAdd(switchedUp, nextDepthOrders);
                        // Before
                        swap(switchedUp.numbers[first + 1], switchedUp.numbers[first]);
                        TryToAdd(switchedUp, nextDepthOrders);
                    }
            }
        }
        
        ++currentDepth;
        
        swap(currentOrders, nextDepthOrders);
    }
    
    return -1;
}



int main()
{
    isPrime[2] = isPrime[3] = isPrime[5] = isPrime[7] =
        isPrime[11] = isPrime[13] = true;
    
    int T = 1;
    int temp;
    while (cin >> temp, temp)
    {
        allOrdersReached.clear();
        Order start;
        start.numbers[0] = abs(temp);
        isMale[start.numbers[0]] = temp > 0;
        
        for (int i = 1; i < Count; ++i)
        {
            cin >> temp;
            start.numbers[i] = abs(temp);
            isMale[start.numbers[i]] = temp > 0;
        }
        
        cout << "Case " << T++ << ": " << GetNumMoves(start)  << '\n';
    }
}

