#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> belowMedian;
    priority_queue<int, std::vector<int>, std::greater<int> > aboveMedian;
    
    int current;
    cin >> current;
    
    // special case, when it did not have any elements
    belowMedian.push(current);
    cout << current << '\n';
    
    int previousMedian = current;
    
    while (cin >> current)
    {
        if (current <= previousMedian)
            belowMedian.push(current);
        else
            aboveMedian.push(current);
        
        if (belowMedian.size() > aboveMedian.size() + 1)
        {
            int swapped = belowMedian.top();
            belowMedian.pop();
            aboveMedian.push(swapped);
        }
        else if (belowMedian.size() < aboveMedian.size())
        {
            int swapped = aboveMedian.top();
            aboveMedian.pop();
            belowMedian.push(swapped);
        }
        
        if (belowMedian.size() == aboveMedian.size())
            previousMedian = belowMedian.top() + (aboveMedian.top() - belowMedian.top()) / 2;
        else
            previousMedian = belowMedian.top();
        
        cout << previousMedian << '\n';
    }
    
}