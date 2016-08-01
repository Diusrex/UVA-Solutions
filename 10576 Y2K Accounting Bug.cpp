#include <iostream>
#include <cmath>

using namespace std;

int CalculateBest(int s, int d)
{
    int maxNumPositive = 5;
    while (maxNumPositive > 0 && s * maxNumPositive  - d * (5 - maxNumPositive) >= 0)
    {
        --maxNumPositive;
    }
    
    int minNumNegative = 5 - maxNumPositive;
    // Can't have any positive in string of 5 months make deficit
    if (maxNumPositive == 0)
        return -1;
    
    int sum = 0;
    int position = 0;
    
    while (position < 12)
    {
        int numPositive = min(12 - position, maxNumPositive);
        sum += numPositive * s;
        
        position += numPositive;
        int numNegative = min(12 - position, minNumNegative);
        sum -= numNegative * d;
        position += numNegative;
    }
    
    return sum;
}


int main()
{
    int s, d;
    while (cin >> s >> d)
    {
        int surplus = CalculateBest(s, d);
        if (surplus < 0)
            cout << "Deficit\n";
        else
            cout << surplus << '\n';
    }
}