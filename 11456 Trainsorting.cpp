#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Similar to Wavio Sequence (10534), determine length for each number descending and ascending
// However, have the ascending and descending occur after the number
// So, descending can be determined normally, since it will set the max length for the final number
// But ascending needs to know the count for the first number, so original algorithm doesnt help
// The determining of length is actually n^2, since need to go backward

int N;


// Need to propagate the count in the opposite direction
// Due to this, is N^2
// Could probably use a different algorithm, but this works
void construct_ascending(const vector<int>& numbers, vector<int>& length)
{
    // Can say they start with default of length 1
    for (int i = 0; i < N; ++i)
        length[i] = 1;
    length.resize(N, 1);
    
    // Propogate backwards
    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        int inc = length[i] + 1;
        for (int j = 0; j < i; ++j)
        {
            // Could possibly be from it
            if (numbers[j] < numbers[i])
                length[j] = max(length[j], inc);
        }
    }
}

// L is the current list. Is not actually a valid increasing subsequence, but using L_id and P, can reconstruct from it
vector<int> L;

// Don't need to do anything odd to finish it
void construct_descending(vector<int>& numbers, vector<int>& length)
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
    vector<int> numbers, reversed, lengthAscending, lengthDescending;
    
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        numbers.resize(N);
        reversed.resize(N);
        lengthAscending.resize(N);
        lengthDescending.resize(N);
        
        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
            reversed[N - i - 1] = numbers[i];
        }
        
        construct_ascending(numbers, lengthAscending);
        construct_descending(reversed, lengthDescending);
        
        //cout << "\n\n";
        // For if N = 0
        int best = 0;
        for (int i = 0; i < N; ++i)
        {
            //cout << numbers[i] << ' ' << (lengthAscending[i] + lengthDescending[N - i - 1]) << ' ' << lengthAscending[i] << ' ' << lengthDescending[N - i - 1] << '\n';
            // -1 since count it twice
            best = max(best, lengthAscending[i] + lengthDescending[N - i - 1] - 1);
        }
        
        cout << best << '\n';
    }
}