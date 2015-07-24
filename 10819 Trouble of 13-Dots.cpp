#include <iostream>

using namespace std;

const int UNKNOWN = -1;

int N;
int M;
int MaxM;

int costs[101];
int favor[101];

// [item][money]
int highestFavor[101][15001];

int GetBestFavor(int currentItem, int moneyUsed)
{
    if (currentItem == N)
    {
        if (moneyUsed <= M || 
            (moneyUsed > 2000 && moneyUsed <= M + 200))
            return 0;
        else
            return -20000;
    }
    
    int &best = highestFavor[currentItem][moneyUsed];
    
    if (best == UNKNOWN)
    {
        int increased = costs[currentItem] + moneyUsed;
        
        int other = -1;
        if (increased <= M + 200)
            other = GetBestFavor(currentItem + 1, increased) + favor[currentItem];
        
        best = GetBestFavor(currentItem + 1, moneyUsed);
        if (other >= 0 || best >= 0)
            best = max(best, other);
    }
    
    return best;
}

int main()
{
    while (cin >> M >> N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> costs[i] >> favor[i];
            
            for (int j = 0; j <= M + 200; ++j)
                highestFavor[i][j] = UNKNOWN;
        }
        
        cout << GetBestFavor(0, 0) << '\n';
    }
}