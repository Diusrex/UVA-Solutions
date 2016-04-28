#include <iostream>

using namespace std;

int N;
int maxNumberWithLoadLeft[1005][3005];

int weight[1005], load[1005];

int GetNumberCanHold(int currentBox, int loadLeft)
{
    if (currentBox == N)
        return 0;
    
    int &num = maxNumberWithLoadLeft[currentBox][loadLeft];
    
    if (num == -1)
    {
        num = GetNumberCanHold(currentBox + 1, loadLeft); // Try not including it
        
        if (loadLeft >= weight[currentBox])
            // Include box
            num = max(num, 1 + GetNumberCanHold(currentBox + 1, 
                    min(loadLeft - weight[currentBox], load[currentBox]))); 
    }
    
    return num;
}


int FindBest()
{
    int best = 0;
    for (int box = 0; box < N; ++box)
    {
        // Starting using this box, and then see how much can hold
        best = max(best, GetNumberCanHold(box + 1, load[box]) + 1);
    }
    return best;
}

int main()
{
    while (cin >> N, N)
    {
        int highestLoad = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> weight[i] >> load[i];
            highestLoad = max(highestLoad, load[i]);
        }
        
        // Reset data
        for (int i = 0; i < N; ++i)
            for (int j = 0; j <= highestLoad; ++j)
                maxNumberWithLoadLeft[i][j] = -1;
        
        cout << FindBest() << '\n';
    }
}
