#include <iostream>
#include <algorithm>

using namespace std;

const double Eps = 1e-6;

bool LessThan(double a, double b)
{
    return a < b + Eps;
}

bool RightSideLengths(double a, double b, double c)
{
    double arr[3] = {a, b, c};
    
    sort(arr, arr + 3);
    
    return LessThan(arr[0], 25.0) && LessThan(arr[1], 45.0) && LessThan(arr[2], 56.0);
}

bool Valid(double a, double b, double c, double weight)
{
    return (RightSideLengths(a, b, c) || LessThan(a + b + c, 125.0)) && LessThan(weight, 7.0);
}

int main()
{
    int T;
    cin >> T;
    
    int numAllowed = 0;
    while (T--)
    {
        double a, b, c, weight;
        cin >> a >> b >> c >> weight;
        
        bool valid = Valid(a, b, c, weight);
        cout << valid << '\n';
        
        if (valid)
            ++numAllowed;
    }
    
    cout << numAllowed << '\n';
}