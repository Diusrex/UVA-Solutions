#include <iostream>

using namespace std;

const int Max = 100;
const int Min = 1;

// No need to use std::sort since can just store counts in array
int count[105];

int main()
{
    int N;
    while (cin >> N, N)
    {
        int age;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> age;
            ++count[age];
        }
        
        string sep = "";
        for (int i = Min; i <= Max; ++i)
        {
            // This will counteract how --count[i] works
            // While leaving the count[i] == 0 after this iteration
            ++count[i];
            
            while (--count[i])
            {
                cout << sep << i;
                sep = " ";
            }
        }
        
        cout << '\n';
    }
}