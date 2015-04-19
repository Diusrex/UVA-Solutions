#include <iostream>
#include <string>

using namespace std;

int SumDigits(const string &num)
{
    int sum = 0;
    
    for (int i = 0; i < num.size(); ++i)
        sum += num[i] - '0';
    
    return sum;
}

int SumDigits(int num)
{
    int sum = 0;
    
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int main()
{
    string line;
    while (cin >> line, line != "0")
    {
        int val = SumDigits(line);
        int count = 1;
        
        // No need to try with any lower value, is either 9 or not
        while (val > 17)
        {
            ++count;
            val = SumDigits(val);
        }
        
        if (val == 9)
            cout << line << " is a multiple of 9 and has 9-degree " << count << ".\n";
        
        else
            cout << line << " is not a multiple of 9.\n";
    }
}