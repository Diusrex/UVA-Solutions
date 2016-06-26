#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// How will do this:
// Sort using MyLT (maybe)
// If largest isn't superset of following, then can just use it
// Then, think include the largest iff the the rest is > the rest
// If it ties, then keep going along until it either 
bool MyLT(const string &lhs, const string &rhs)
{
    if (lhs[0] != rhs[0])
        return lhs[0] > rhs[0];
    
    for (int i = 1; i % lhs.size() != 0 || i % rhs.size() != 0; ++i)
        if (lhs[i % lhs.size()] != rhs[i % rhs.size()])
            return lhs[i % lhs.size()] > rhs[i % rhs.size()];
    
    return lhs.size() < rhs.size();
}

string numbers[55];



int main()
{
    int N;
    
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        sort(numbers, numbers + N, MyLT);
        
        for (int i = 0; i < N; ++i)
        {
            cout << numbers[i];
        }
        cout << '\n';
    }
}