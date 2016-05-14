#include <iostream>

using namespace std;

int numbers[101];

int main()
{
    
    for (int i = 1; i <= 100; ++i)
        numbers[i] = numbers[i - 1] + i * i;
    
    int N;
    
    while (cin >> N, N)
    {
        cout << numbers[N] << '\n';
    }
}