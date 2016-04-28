#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lengthOfIncreasing;

// L is the current list. Is not actually a valid increasing subsequence, but using L_id and P, can reconstruct from it
// L_id[i] stores the index for the number stored in L at position i
vector<int> L;
vector<int> L_id;

void construct(const vector<int>& numbers)
{
    L.clear();
    lengthOfIncreasing = 0;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        const int num = numbers[i];

        // Change to upper_bound for not strictly increasing
        int pos = upper_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            L.push_back(num);
        }
        else
        {
            L[pos] = num;
        }

        // >= since to output the latest one
        if (pos + 1 >= lengthOfIncreasing) {
            lengthOfIncreasing = pos + 1;
        }
    }
}

int main()
{
    vector<int> numbers;
    int T = 1;
    
    int num;
    
    string sep = "";
    
    while (cin >> num, num != -1)
    {
        numbers.clear();
        numbers.push_back(num);
        
        while (cin >> num, num != -1)
            numbers.push_back(num);
        
        reverse(numbers.begin(), numbers.end());
        construct(numbers);
        
        cout << sep << "Test #" << T++ << ":\n  maximum possible interceptions: " << lengthOfIncreasing << '\n';
        sep = "\n";
    }
}