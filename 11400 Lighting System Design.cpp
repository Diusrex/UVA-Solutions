#include <iostream>
#include <algorithm>

using namespace std;


// at most, 1000 * 100 lamps
// also, 1000 different categories
// cost at [c][L] -> number of additional lamps L needed at c
// is min-max -> use them all, or use none for the current lamp

struct Category
{
    int voltage;
    int voltageCost, lampCost;
    int numBaseLamps;
    
    // Order by increasing voltage
    bool operator<(const Category& other) const
    {
        return voltage < other.voltage;
    }
};

const int MaxNumCategories = 1001;
const int MaxNumLamps = MaxNumCategories * 101;
int N;
int costs[MaxNumCategories][MaxNumLamps];

Category categories[MaxNumCategories];

int GetBestCost(int category, int lampsCarried)
{
    if (category == N)
        return 0;
    int& cost = costs[category][lampsCarried];
    
    if (cost == -1)
    {
        const Category& current = categories[category];
        int numLamps = current.numBaseLamps + lampsCarried;
        cost = current.voltageCost + numLamps * current.lampCost
                    + GetBestCost(category + 1, 0); // Have all lamps be current category
                    
        // Don't get into situation where lampsCarried != 0 for category == N
        if (category + 1 != N)
            cost = min(cost, GetBestCost(category + 1, numLamps)); // Don't use this category
    }
    
    return cost;
}

int main()
{
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
        {
            Category& c = categories[i];
            cin >> c.voltage >> c.voltageCost >> c.lampCost >> c.numBaseLamps;
        }
        
        sort(categories, categories + N);
        
        // Reset costs
        int totalLamps = 0; // Total that could have been carried up to this point
        for (int i = 0; i < N; ++i)
        {
            for (int l = 0; l <= totalLamps; ++l)
            {
                costs[i][l] = -1;
            }
            totalLamps += categories[i].numBaseLamps;
        }
        
        cout << GetBestCost(0, 0) << '\n';
    }
}