#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    while (cin >> N, N)
    {
        int best = 0, current = 0;
        while (N--)
        {
            int temp;
            cin >> temp;
            current += temp;
            if (current < 0)
                current = 0;
            else if (current > best)
                best = current;
        }
        
        if (best)
            cout << "The maximum winning streak is " << best << ".\n";
        else
            cout << "Losing streak.\n";
    }
}