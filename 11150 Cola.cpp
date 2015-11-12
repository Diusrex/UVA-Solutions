#include <iostream>

using namespace std;

int GetNum(int empty)
{
    if (empty == 2)
        return 1;
    else if (empty < 2)
        return 0;
    
    
    // Refill a third
    return GetNum(empty / 3 + empty % 3) + empty / 3;
}

int main()
{
    int N;
    
    while (cin >> N)
    {
        cout << (GetNum(N) + N) << '\n';
    }
}