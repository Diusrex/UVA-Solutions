#include <iostream>
#include <set>

using namespace std;

int main()
{
    int numDays;
    
    while (cin >> numDays, numDays)
    {
        // Can use a set because they are sorted based on value
        multiset<int> numbers;
        
        // Could be very large
        long long cost = 0;
        
        while (numDays--)
        {
            int k;
            cin >> k;
            
            while (k--)
            {
                int t;
                cin >> t;
                
                numbers.insert(t);
            }
            
            multiset<int>::iterator lowest = numbers.begin();
            multiset<int>::iterator highest = --numbers.end();
            
            
            cost += *highest - *lowest;
            
            numbers.erase(lowest); numbers.erase(highest);
        }
        
        cout << cost << '\n';
    }
}
