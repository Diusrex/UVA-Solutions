#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// End is the index in numbers of last number for longest subsequence
int lengthOfIncreasing, endOfLatest;

// L is the current list. Is not actually a valid increasing subsequence, but using L_id and P, can reconstruct from it
// L_id[i] stores the index for the number stored in L at position i. Only necessary if you need to reconstruct the sequence
vector<int> L;
vector<int> L_id;

// P is what index came before a number. Only necessary if you need to reconstruct the sequence
vector<int> P;

void construct(const vector<int>& numbers)
{
    L.clear();
    L_id.clear();
    P.clear();
    lengthOfIncreasing = endOfLatest = 0;
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        const int num = numbers[i];

        // Change to upper_bound for not strictly increasing
        int pos = lower_bound(L.begin(), L.end(), num) - L.begin();
        if (pos == L.size())
        {
            L.push_back(num);
            L_id.push_back(i);
        }
        else
        {
            L[pos] = num;
            L_id[pos] = i;
        }

        P.push_back(pos ? L_id[pos - 1] : -1);

        // >= since to output the latest one
        if (pos + 1 >= lengthOfIncreasing) {
            lengthOfIncreasing = pos + 1;
            endOfLatest = i;
        }
    }
}

// End is the index in numbers of last number for wanted subsequence
// To get solution, will normally want to do reconstruct_print(endOfLatest)
// To get the length of longest, use lengthOfIncreasing
void reconstruct_print(const vector<int>& numbers, int end) {
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
    int T;
    cin >> T;
    
    string sep = "";
    
    while (T--)
    {
        vector<int> numbers;
        
        int num;
        cin >> num;
        numbers.push_back(num);
        cin.ignore();
        
        while (cin.peek() >= '0' && cin.peek() <= '9')
        {
            cin >> num;
            numbers.push_back(num);
            cin.ignore();
        }
        
        construct(numbers);
        
        cout << sep << "Max hits: " << lengthOfIncreasing << '\n';
        sep = "\n";
        reconstruct_print(numbers, endOfLatest);
    }
}