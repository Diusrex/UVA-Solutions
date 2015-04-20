#include <iostream>
#include <string>

using namespace std;

int GetSum(const string &num)
{
    int sum = 0;
    for (int i = 0; i < num.size(); ++i)
        sum += num[i] - '0';
    
    return sum;
}

bool CanMakeSumDivisibleBy3(int sum, const string &num)
{
    for (int i = 0; i < num.size(); ++i)
        if ((sum - (num[i] - '0')) % 3 == 0)
            return true;
    
    return false;
}

int GetNumDivisibleBy3(const string &num)
{
    int count = 0;
    for (int i = 0; i < num.size(); ++i)
    {
        if ((num[i] - '0') % 3 == 0)
            ++count;
    }
    
    return count;
}

inline void Print(int t, char o)
{
    cout << "Case " << t << ": " << o << '\n';
}

int main()
{
    int T;
    cin >> T;
    
    string num;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> num;
        
        // Special case
        if (num.size() == 1)
        {
            Print(t, 'S');
            continue;
        }
        
        int sum = GetSum(num);
        if (sum % 3 == 0)
            Print(t, (GetNumDivisibleBy3(num) % 2 == 1) ? 'S' : 'T');
        else if (CanMakeSumDivisibleBy3(sum, num))
            Print(t, (GetNumDivisibleBy3(num) % 2 == 0) ? 'S' : 'T');
        else
            Print(t, 'T');
    }
}