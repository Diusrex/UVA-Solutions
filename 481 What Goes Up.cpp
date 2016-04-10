#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> numbers;

int lengthOfIncreasing, endOfLatest;
// L is the current list. Is not actually a valid increasing subsequence, but using L_id and P, can reconstruct from it
// L_id stores the index for the number stored in L
vector<int> L;
vector<int> L_id;

// P is what index came before a number
vector<int> P;

// The ascending subsequence code is from Competitive Programming 3

int LoadInputAndProcess()
{
    int num;
    while (cin >> num)
    {
        int index = numbers.size();
        numbers.push_back(num);
        
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            L.push_back(num);
            L_id.push_back(index);
        }
        else
        {
            L[pos] = num;
            L_id[pos] = index;
        }
        
        P.push_back(pos ? L_id[pos - 1] : -1);
        
        // >= since need to output the latest one
        if (pos + 1 >= lengthOfIncreasing) {
            lengthOfIncreasing = pos + 1;
            endOfLatest = index;
        }
    }
}
  
// End is the index in numbers of last number for longest subsequence
void reconstruct_print(int end) {
    int x = end;
    stack<int> s;
    for (; P[x] >= 0; x = P[x])
    {
        s.push(numbers[x]);
    }
    s.push(numbers[x]);
    for (; !s.empty(); s.pop())
        cout << s.top() << '\n';
}

int main()
{
    LoadInputAndProcess();
    
    cout << lengthOfIncreasing << "\n-\n";
    reconstruct_print(endOfLatest);
}