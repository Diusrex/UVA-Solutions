#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int n;
        cin >> n;
     
        long highestTotal(0), highestStart(0), highestEnd(0);
        
        long currentCount(0), currentStart(0);

        int value;
        
        for (int i = 1; i < n; ++i)
        {
            cin >> value;
            
            currentCount += value;
            
            if (currentCount < 0)
            {
                currentCount = 0;
                currentStart = i;
            }
            
            else if (currentCount > highestTotal || (currentCount == highestTotal && i - currentStart > highestEnd - highestStart))
            {
                highestTotal = currentCount;
                highestStart = currentStart;
                highestEnd = i;
            }
        }
        
        if (currentCount > highestTotal)
        {
            highestTotal = currentCount;
            highestEnd = n;
            highestStart = currentStart;
        }
        
        if (highestTotal <= 0)
            cout << "Route " << t << " has no nice parts\n";
            
        else
            cout << "The nicest part of route " << t << " is between stops " << highestStart + 1 << " and " << highestEnd + 1 << '\n';
    }

}