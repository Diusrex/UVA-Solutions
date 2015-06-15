#include <iostream>
#include <vector>

using namespace std;

int parties[123];
int N, P;

bool IsDayOff(int d)
{
    for (int i = 0; i < P; ++i)
        if (d % parties[i] == 0)
            return true;
        
    return false;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N >> P;
        
        for (int i = 0; i < P; ++i)
            cin >> parties[i];
        
        int count = 0;
        for (int d = 1; d <= N; ++d)
        {
            // d = 1 means sunday
            // 
            if (d % 7 != 6 && d % 7 != 0 && IsDayOff(d))
                ++count;
        }
        
        cout << count << '\n';
    }
}