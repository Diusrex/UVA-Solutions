#include <iostream>

using namespace std;

const int MaxTime = 1000001;

bool Occurs[MaxTime + 1];

int main()
{
    int N, M;
    
    while (cin >> N >> M, N + M)
    {
        bool valid = true;
        
        for (int i = 0; i < MaxTime; ++i)
                Occurs[i] = false;
        
        for (int i = 0; i < N; ++i)
        {
            int start, end;
            cin >> start >> end;
            for (int spot = start; valid && spot < end; ++spot)
            {
                valid = !Occurs[spot];
                Occurs[spot] = true;
            }
        }
        
        for (int i = 0; i < M; ++i)
        {
            int start, end, interval;
            cin >> start >> end >> interval;
            
            while (valid && start < MaxTime)
            {
                for (int spot = start; valid && spot < end; ++spot)
                {
                    valid = !Occurs[spot];
                    Occurs[spot] = true;
                }
                
                start += interval;
                end = min(end + interval, MaxTime);
            }
        }
        
        if (valid)
            cout << "NO CONFLICT\n";
        else
            cout << "CONFLICT\n";
    }
}