#include <iostream>

using namespace std;

int numbers[100005];

int main()
{
    int N, S;
    while (cin >> N >> S)
    {
        int currentS = 0;
        int numElementsUsed = 0;
        int minElements = N + 5;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
            currentS += numbers[i];
            ++numElementsUsed;
            
            if (currentS >= S)
            {
                int tryRemoving = i - numElementsUsed + 1;
                
                while (currentS - numbers[tryRemoving] >= S)
                {
                    currentS -= numbers[tryRemoving];
                    ++tryRemoving;
                    --numElementsUsed;
                }
                
                minElements = min(minElements, numElementsUsed);
            }
            
        }
        
        
        
        if (minElements > N)
            cout << "0\n";
        else
            cout << minElements << '\n';
    }
}
