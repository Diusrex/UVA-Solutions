#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int first, second, third;
    
    while (cin >> first)
    {
        vector<vector<int> > bins(3, vector<int>(3));
        
        for (int i = 0; i < 3; ++i)
        {
            cin >> third >> second;
            bins[i][0] = first;
            bins[i][1] = second;
            bins[i][2] = third;
            
            if (i != 2)
                cin >> first;
        }
        
        vector<char> conversions(3);
        conversions[0] = 'B'; conversions[1] = 'C'; conversions[2] = 'G';
        
        vector<int> order(3);
        order[0] = 0; order[1] = 1; order[2] = 2;
        
        long lowestTotal = -1;
        vector<int> bestArrangement;
        
        do {
            long currentTotal(0);
            
            for (int i = 0; i < 3; ++i)
            {
                for (int b = 0; b < 3; ++b)
                {
                    if (b != order[i])
                        currentTotal += bins[i][b];
                }
            }
            
            if (currentTotal < lowestTotal || lowestTotal == -1)
            {
                lowestTotal = currentTotal;
                bestArrangement = order;
            }
        } while (next_permutation(order.begin(), order.end()));
        
        
        cout << conversions[bestArrangement[0]] << conversions[bestArrangement[1]] << conversions[bestArrangement[2]] << ' ' << lowestTotal << '\n';
    }

}