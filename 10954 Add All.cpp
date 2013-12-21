#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main()
{
    int n;
    cin >> n;
    
    while (n)
    {
        vector<long> origionalNums(n);
        for (int i = 0; i < n; ++i)
            cin >> origionalNums[i];
            
        priority_queue<int,std::vector<int>,greater<int> > q(origionalNums.begin(), origionalNums.end());
        
        int cost(0);
        int count(0);
        
        while (count < n - 1)
        {
            int temp = q.top(); q.pop();
            temp += q.top(); q.pop();
            q.push(temp);
            cost += temp;
            ++count;
        }

        cout << cost << '\n';
        cin >> n;
    }

}