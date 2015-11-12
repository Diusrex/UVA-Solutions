#include <iostream>

using namespace std;

unsigned int numbers[100005];

int main()
{
    int N, T = 1;
    
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        numbers[N] = 0; // Never common with the one before it
        
        cout << "Case " << T++ << ":\n";
        
        for (int i = 0; i < N; ++i)
        {
            if (numbers[i] + 1 != numbers[i + 1])
                cout << '0' << numbers[i] << '\n';
            else
            {
                cout << '0' << numbers[i] << '-';
                int subsequent = i + 1;
                for (; numbers[subsequent] + 1 == numbers[subsequent + 1]; ++subsequent)
                    ;
                unsigned int start = numbers[i], end = numbers[subsequent];
                //cout << "\nS: " << start << ' ' << end << '\n';
                
                unsigned int mod = 10;
                while (start - (start % mod) != end - (end % mod))
                    mod *= 10;
                //cout << "Mod: " << mod << '\n';
                cout << (end % mod) << '\n';
                i = subsequent;
            }
        }
        
        cout << '\n';
    }
}