#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int Inf = 1e9;

int youngCost[27][27];
int oldCost[27][27];

void AddEdge(char direction, char X, char Y, int cost, int array[27][27])
{
    array[X - 'A'][Y - 'A'] = min(cost, array[X - 'A'][Y - 'A']);
    if (direction == 'B')
        array[Y - 'A'][X - 'A'] = min(cost, array[Y - 'A'][X - 'A']);
        
}

int main()
{
    int E;
    while (cin >> E, E)
    {
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
                youngCost[i][j] = oldCost[i][j] = Inf;
            youngCost[i][i] = oldCost[i][i] = 0;
        }
        
        while (E--)
        {
            int cost;
            char age, direction, X, Y;
            cin >> age >> direction >> X >> Y >> cost;
            if (age == 'Y')
                AddEdge(direction, X, Y, cost, youngCost);
            else
                AddEdge(direction, X, Y, cost, oldCost);
        }
        
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                {
                    youngCost[i][j] = min(youngCost[i][j], youngCost[i][k] + youngCost[k][j]);
                    oldCost[i][j] = min(oldCost[i][j], oldCost[i][k] + oldCost[k][j]);
                }
        
        int cost = Inf - 1;
        char youngS, oldS;
        vector<char> meetSpots;
        cin >> youngS >> oldS;
        
        for (int meet = 0; meet < 26; ++meet)
        {
            int cCost = youngCost[youngS - 'A'][meet] + oldCost[oldS - 'A'][meet];
            if (cCost < cost)
            {
                meetSpots.clear();
                meetSpots.push_back(meet + 'A');
                cost = cCost;
            }
            else if (cCost == cost)
                meetSpots.push_back(meet + 'A');
        }
        
        if (meetSpots.size())
        {
            cout << cost;
            for (int i = 0; i < meetSpots.size(); ++i)
                cout << ' ' << meetSpots[i];
            cout << '\n';
        }
        else
            cout << "You will never meet.\n";
    }
    
}