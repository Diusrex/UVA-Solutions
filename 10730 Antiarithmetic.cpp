#include <iostream>
#include <algorithm>

using namespace std;

int numReachedBy[10005];
int nums[10005];

int main()
{
    int N;
    while (cin >> N, N)
    {
        char junk;
        cin >> junk;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> nums[i];
            numReachedBy[nums[i]] = i;
        }
        
        bool isSeq = true;
        for (int i = 0; i < N && isSeq; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                int third = 2 * nums[j] - nums[i];
                if (third >= 0 && third < N)
                {
                    if (numReachedBy[third] > j)
                    {
                        isSeq = false;
                        break;
                    }
                }
            }
        }
        if (isSeq)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}