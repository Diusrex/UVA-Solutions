#include <iostream>
#include <vector>

typedef unsigned long long mainInt;

const mainInt MAX_VAL = 1000000000;

using namespace std;

int main()
{
    int c, r, q;
    
    int T = 1;
    while (cin >> c >> r >> q, c + r + q)
    {
        if (T != 1)
            cout << '\n';
        
        ++c;
        vector<vector<mainInt> > worstFeastCosts(c, vector<mainInt>(c, MAX_VAL));
        for (int i = 1; i < c; ++i)
            cin >> worstFeastCosts[i][i];
        
        vector<vector<mainInt> > travelCosts(c, vector<mainInt>(c, MAX_VAL));
        for (int i = 0; i < r; ++i)
        {
            int start, end;
            mainInt current;
            cin >> start >> end >> current;
            if (current < travelCosts[start][end])
            {
                travelCosts[start][end] = current;
                travelCosts[end][start] = current;
                
                // Need to do this
                mainInt feastCost = max(worstFeastCosts[start][start], worstFeastCosts[end][end]);
                worstFeastCosts[start][end] = feastCost;
                worstFeastCosts[end][start] = feastCost;
            }
        }
        
        // Need to run Floyd-Warshall's Algorithm twice. This is because of the interaction
            // of the worstFeastCosts
        for (int p = 0; p < 2; ++p)
            for (int k = 1; k < c; ++k)
                for (int i = 1; i < c; ++i)
                    for (int j = 1; j < c; ++j)
                    {
                        mainInt worstFeast = max(worstFeastCosts[i][k], worstFeastCosts[k][j]);
                        if (travelCosts[i][j] + worstFeastCosts[i][j] > travelCosts[i][k] + travelCosts[k][j] + worstFeast)
                        {
                            travelCosts[i][j] = travelCosts[i][k] + travelCosts[k][j];
                            worstFeastCosts[i][j] = worstFeast;
                        }
                    }
                
        cout << "Case #" << T++ << '\n';
        for (int i = 0; i < q; ++i)
        {
            int start, end;
            cin >> start >> end;
            if (travelCosts[start][end] == MAX_VAL)
                cout << -1 << '\n';
            else
                cout << travelCosts[start][end] + worstFeastCosts[start][end] << '\n';
        }
    }
}