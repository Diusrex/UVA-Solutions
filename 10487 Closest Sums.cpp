#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int nums[1005];

int main()
{
    int N, T = 1;
    
    while (cin >> N, N != 0)
    {
        set<int> sums;
        for (int i = 0; i < N; ++i)
        {
            cin >> nums[i];
            for (int j = 0; j < i; ++j)
                if (nums[j] != nums[i])
                    sums.insert(nums[j] + nums[i]);
        }
        
        int Q;
        cin >> Q;
        
        cout << "Case " << T++ << ":\n";
        while (Q--)
        {
            int num, best;
            cin >> num;
            
            set<int>::iterator iter = sums.lower_bound(num);
            if (iter == sums.begin())
                best = *iter; // Since is at least as high as this number
            else if (iter == sums.end())
            {
                --iter;
                best = *iter;
            }
            else
            {
                best = *iter;
                --iter;
                if (abs(best - num) > abs(*iter - num))
                    best = *iter;
            }
            
            cout << "Closest sum to " << num << " is " << best << ".\n";
        }
    }
}