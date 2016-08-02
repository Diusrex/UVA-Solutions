#include <iostream>


using namespace std;

int N, K;
// [campsite][nightsLeft]
int bestTime[605][305];
int distanceToPrev[610];

int GetBestTime(int campsite, int nightsLeft)
{
    if (campsite == N)
        return 0;
    else if (nightsLeft == 0)
    {
        int sum = 0;
        // Sum up all distances
        for (int i = campsite; i < N; ++i)
            sum += distanceToPrev[i];
        return sum;
    }
    
    int &best = bestTime[campsite][nightsLeft];
    
    if (best == -1)
    {
        best = 2e9;
        int distance = distanceToPrev[campsite];
        for (int next = campsite + 1; next <= N && best > distance; distance += distanceToPrev[next], ++next)
        {
            best = min(best,
                max(distance, GetBestTime(next, nightsLeft - 1)));
        }
    }
    
    return best;
}

int main()
{
    while (cin >> N >> K)
    {
        ++N;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> distanceToPrev[i];
        }
        
        for (int i = 0; i < N; ++i)
        {
            for (int k = 0; k <= K; ++k)
                bestTime[i][k] = -1;
        }
        
        cout << GetBestTime(0, K) << '\n';
    }
}