#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<long long, int> length;

int get_longest(long long num)
{
    if (num == 1)
        return 0;
    if (length.find(num) != length.end())
        return length.find(num)->second;
    
    int len;
    if (num % 2)
        len = get_longest(num * 3 + 1) + 1;
    else
        len = get_longest(num / 2) + 1;
    
    length[num] = len;
    
    return len;
}

int main()
{
    
    long long a, b;
    while (cin >> a >> b, a)
    {
        long long start = min(a, b), end = max(a, b);
        long long longestNum = 0;
        int longestLength = 0;
        
        for (long long i = start; i <= end; ++i)
        {
            int current = get_longest(i);
            if (i == 1)
                current = 3;
            if (current > longestLength)
            {
                longestLength = current;
                longestNum = i;
            }
        }
        
        cout << "Between " << start << " and " << end << ", " << longestNum << " generates the longest sequence of " << longestLength << " values.\n";
    }
    
}