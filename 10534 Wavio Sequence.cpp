#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// L is the current list. Is not actually a valid increasing subsequence, but using L_id and P, can reconstruct from it
vector<int> L;

void construct(const vector<int>& numbers, vector<int>& length)
{
    L.clear();
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        const int num = numbers[i];

        // Change to upper_bound for not strictly increasing
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            L.push_back(num);
        }
        else
        {
            L[pos] = num;
        }

        length[i] = pos + 1;
    }
}


int main()
{
    int N;
    vector<int> numbers, lengthAscending, lengthDescending;
    
    while (cin >> N)
    {
        numbers.resize(N);
        lengthAscending.resize(N);
        lengthDescending.resize(N);
        
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        construct(numbers, lengthAscending);
        reverse(numbers.begin(), numbers.end());
        construct(numbers, lengthDescending);
        
        int best = 1;
        for (int i = 0; i < N; ++i)
        {
            int lowest = min(lengthAscending[i], lengthDescending[N - i - 1]);
            best = max(best, lowest * 2 - 1);
        }
        
        cout << best << '\n';
    }
}