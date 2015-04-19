#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
    int start, end;
    
    bool operator<(const Pair & other) const
    {
        return start < other.start;
    }
};

Pair allPairs[100005];
Pair solution[100005];

int main()
{
    string sep = "";
    int T, M;
    
    cin >> T;
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        cin >> M;
        
        int numPairs = 0;
        while (cin >> allPairs[numPairs].start >> allPairs[numPairs].end,
            allPairs[numPairs].start || allPairs[numPairs].end)
        {
            // If not, ignore it
            if (allPairs[numPairs].end > 0 && allPairs[numPairs].start < M)
                ++numPairs;
        }
        
        sort(allPairs, allPairs + numPairs);
        
        // Ensure this will never be selected
        allPairs[numPairs].start = M + 1;
        
        int count = 0;
        int currentX = 0;
        int currentPair = 0;
        
        // Pick the best end out of all of the possible pairs
        while (currentX < M && currentPair < numPairs)
        {
            solution[count].end = 0;
            for (; allPairs[currentPair].start <= currentX; ++currentPair)
                if (allPairs[currentPair].end > solution[count].end)
                    solution[count] = allPairs[currentPair];
            
            if (solution[count].end == currentX)
            {
                break;
            }
            currentX = solution[count].end;
            ++count;
        }
        
        if (currentX >= M)
        {
            cout << count << '\n';
            
            for (int i = 0; i < count; ++i)
            {
                cout << solution[i].start << ' ' << solution[i].end << '\n';
            }
        }
        else
            cout << "0\n";
    }
}