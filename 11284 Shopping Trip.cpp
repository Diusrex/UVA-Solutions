#include <iostream>
#include <iomanip>

using namespace std;

const int Inf = 1e9;
int BaseCosts[51][51];

int NumOpera;
int StoreNum[14];
int StoreSaved[14];
int DirectCosts[14][14];

// Based on node at, which have visited previously
bool visited[14][1 << 14 + 1];
int bestSaved[14][1 << 14 + 1];

int TryOut(int index, int travelledTo)
{
    int &best = bestSaved[index][travelledTo];
    if (!visited[index][travelledTo])
    {
        visited[index][travelledTo] = true;
        
        // Go back immediately. Will add store bonus later
        best = -DirectCosts[index][0];
        
        for (int i = 0; i <= NumOpera; ++i)
        {
            if (!(travelledTo & (1 << i)))
                best = max(best,
                           TryOut(i, travelledTo | (1 << i)) - DirectCosts[index][i]);
        }
        
        best += StoreSaved[index];
    }
    
    return best;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        ++N;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                BaseCosts[i][j] = Inf;
            BaseCosts[i][i] = 0;
        }
        
        while (M--)
        {
            int start, end, dollars, cents;
            char junk;
            cin >> start >> end >> dollars >> junk >> cents;
            
            BaseCosts[start][end] = BaseCosts[end][start] =
                min(BaseCosts[end][start], dollars * 100 + cents);
        }
        
        // Calculate travel costs between all stores
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    BaseCosts[i][j] = min(BaseCosts[i][j], BaseCosts[i][k] + BaseCosts[k][j]);
        
        StoreNum[0] = 0;
        cin >> NumOpera;
        for (int i = 1; i <= NumOpera; ++i)
        {
            int dollars, cents;
            char junk;
            cin >> StoreNum[i] >> dollars >> junk >> cents;
            StoreSaved[i] = dollars * 100 + cents;
            
            for (int j = 0; j < i; ++j)
                DirectCosts[i][j] = DirectCosts[j][i] = BaseCosts[StoreNum[i]][StoreNum[j]];
        }
        
        // TODO: Try having all gone to
        for (int i = 0; i <= NumOpera; ++i)
        {
            for (int j = 0; j <= (1 << (NumOpera + 2) - 1); ++j)
                visited[i][j] = false;
        }
        
        int best = TryOut(0, 0);
        
        if (best > 0)
            cout << "Daniel can save $" << (best / 100) << '.' << setw(2) << setfill('0') << (best % 100) << '\n';
        else
            cout << "Don't leave the house\n";
    }
}