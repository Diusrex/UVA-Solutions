#include <iostream>
#include <queue>
#include <functional>

using namespace std;

const int MaxNum = 5845;
long long numbers[MaxNum];

string GetSuffix(int n)
{
    n = n % 100;
    if (n > 10 && n < 20)
        return "th";
    else if (n % 10 == 1)
        return "st";
    else if (n % 10 == 2)
        return "nd";
    else if (n % 10 == 3)
        return "rd";
    else
        return "th";
}

int main()
{
    int index = 1;
    
    priority_queue<long long, vector<long long>, greater<long long> > nums;
    nums.push(1);
    
    for (; index < MaxNum; ++index)
    {
        long long num = nums.top();
        nums.pop();
        
        while (!nums.empty() && nums.top() == num)
            nums.pop();
        
        numbers[index] = num;
        
        nums.push(num * 2);
        nums.push(num * 3);
        nums.push(num * 5);
        nums.push(num * 7);
    }
    
    int n;
    
    while (cin >> n && n)
    {
        
        cout << "The " << n << GetSuffix(n) << " humble number is " << numbers[n] << ".\n";
    }
}