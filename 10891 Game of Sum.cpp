#include <iostream>

using namespace std;

//  Will take a group of positive numbers from either side
// If there are negative numbers

// So the cost would be:
    // Maximized sum from either end - nextDifference()

// Will use DP

// These are [leftBound][rightBound]
int numbers[105];

bool seen[105][105];
int differenceForCurrent[105][105];

// Would be n ^ 3, because need to scan up to n each time, and there will be ~n^2 for dp

// All endpoints will be inclusive

int TryLeftSide(int left, int right);
int TryRightSide(int left, int right);

int GetBestForCurrentPlayer(int left, int right)
{
    if (left > right)
        return 0;
    
    int &diff = differenceForCurrent[left][right];
    if (!seen[left][right])
    {
        // Try both sides, and choose the best
        diff = max(TryLeftSide(left, right), TryRightSide(left, right));
        
        seen[left][right] = true;
    }
    
    return diff;
}

int TryLeftSide(int left, int right)
{
    int currentSum = numbers[left];
    int bestDiff = currentSum - GetBestForCurrentPlayer(left + 1, right);
    
    for (int i = left + 1; i <= right; ++i)
    {
        currentSum += numbers[i];
        int nextDiff = currentSum - GetBestForCurrentPlayer(i + 1, right);
        if (nextDiff > bestDiff)
            bestDiff = nextDiff;
    }
    
    return bestDiff;
}

int TryRightSide(int left, int right)
{
    int currentSum = numbers[right];
    int bestDiff = currentSum - GetBestForCurrentPlayer(left, right - 1);
    
    for (int i = right - 1; i >= left; --i)
    {
        currentSum += numbers[i];
        int nextDiff = currentSum - GetBestForCurrentPlayer(left, i - 1);
        if (nextDiff > bestDiff)
            bestDiff = nextDiff;
    }
    
    return bestDiff;
}


int main()
{
    int N;
    
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                seen[i][j] = false;
            }
        }
        
        cout << GetBestForCurrentPlayer(0, N - 1) << '\n';
    }
}

