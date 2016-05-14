#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int GetNumDigits(int num)
{
    int count = 0;
    
    while (num)
    {
        num /= 10;
        ++count;
    }
    
    return count;
}

int GCD(int a, int b)
{
    if (b)
        return GCD(b, a % b);
    return a;
}

void PrintNum(int num, bool isNeg, int preceedLength, int longest)
{
    if (isNeg)
        cout << "  ";
    cout << string(preceedLength, ' ') << setw(longest) << num << '\n';
}

int main()
{
    int N, T = 1;
    
    while (cin >> N, N)
    {
        int sum = 0, num;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            sum += num;
        }
        
        cout << "Case " << T++ << ":\n";
        if (sum % N == 0)
        {
            if (sum < 0)
                cout << "- ";
            cout << abs(sum / N) << '\n';
        }
        else
        {
            bool isNeg = (sum < 0);
            sum = abs(sum);
            
            int preceed = sum / N;
            int preceedLength = GetNumDigits(preceed);
            
            sum = sum % N;
            
            int gcd = GCD(sum, N);
            int num = sum / gcd, denom = N / gcd;
            
            int longest = max(GetNumDigits(num), GetNumDigits(denom));
            
            PrintNum(num, isNeg, preceedLength, longest);
            if (isNeg)
                cout << "- ";
            if (preceed)
                cout << preceed;
            cout << string(longest, '-') << '\n';
            PrintNum(denom, isNeg, preceedLength, longest);
        }
    }
}