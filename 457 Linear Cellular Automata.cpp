#include <string>
#include <iostream>
#include <vector>

using namespace std;

const string firstOutput = "                   .                    ";
const int NUM_DISHES = 40;

char numToChar(const int & num)
{
    if (num == 0)
        return ' '; // EDIT: Testing only
    else if (num == 1)
        return '.';
    else if (num == 2)
        return 'x';
    else
        return 'W';
}

string Tick(vector<int>& neighborCount, const vector<int>& DNA)
{
    string line(NUM_DISHES, ' ');
    static vector<int> newNeighborCount(NUM_DISHES);
    for (int i = 0; i < NUM_DISHES; ++i)
        newNeighborCount[i] = 0;
    
    for (int i = 0; i < NUM_DISHES; ++i)
    {
        int newValue = DNA[neighborCount[i]];
        
        if (i != 0)
            newNeighborCount[i - 1] += newValue;
            
        newNeighborCount[i] += newValue;
        
        if (i != NUM_DISHES - 1)
            newNeighborCount[i + 1] += newValue;
        
        
        line[i] = numToChar(newValue);
    }
    
    neighborCount.swap(newNeighborCount);
    
    return line;
}

int main()
{
    int T;
    cin >> T;
    
    vector<int> DNA(10);
    
    vector<int> neighborCounts(NUM_DISHES);
    bool first = true;
    while (T--)
    {
        if (!first)
            cout << '\n';
        first = false;
        
        for (int i = 0; i < NUM_DISHES; ++i)
            neighborCounts[i] = 0;
        
        for (int i = 0; i < 10; ++i)
            cin >> DNA[i];
            
        neighborCounts[18] = neighborCounts[19] = neighborCounts[20] = 1;
        cout << firstOutput << '\n';
        int t = 49; // For my method, first case is special
        
        while (t--)
            cout << Tick(neighborCounts, DNA) << '\n';
    }
}