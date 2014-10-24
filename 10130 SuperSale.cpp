#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

const int MAX_WEIGHT = 31;
int bestForWeight[MAX_WEIGHT]; // Will store the best value for the weight

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        for (int i = 0; i < MAX_WEIGHT; ++i)
            bestForWeight[i] = 0;
        
        int nItems;
        cin >> nItems;
        
        for (int item = 0; item < nItems; ++item)
        {
            int itemWeight, itemValue;
            cin >> itemValue >> itemWeight;
            
            for (int weight = MAX_WEIGHT - 1; weight >= itemWeight; --weight)
            {
                bestForWeight[weight] = max(bestForWeight[weight], bestForWeight[weight - itemWeight] + itemValue);
            }
        }
        
        int total = 0, numPeople;
        int weight;
        
        cin >> numPeople;
        
        for (int i = 0; i < numPeople; ++i)
        {
            cin >> weight;
            total += bestForWeight[weight];
        }
        
        cout << total << '\n';
    }
}