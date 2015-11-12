#include <iostream>


using namespace std;

long long sums[50005];

inline long long cube(long long num)
{
    return num * num * num;
}

int main()
{
    sums[1] = 1;
    sums[2] = 9;
    for (int i = 3; i <= 50000; ++i)
        sums[i] = sums[i - 1] + cube(i);
    
    int num;
    while (cin >> num)
        cout << sums[num] << '\n';
}