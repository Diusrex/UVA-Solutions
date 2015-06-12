#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        vector<int> numbers(N);
        
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        int cost = 0;
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (numbers[i] > numbers[j])
                    ++cost;
            }
        }
        
        
        cout << "Minimum exchange operations : " << cost << "\n";
    }
}