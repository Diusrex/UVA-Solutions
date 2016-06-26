#include <iostream>

using namespace std;

const int NumCards = 5;
const int Cards[NumCards] = {10000, 1000, 100, 10, 1}; 

int main()
{
    int N, M;
    
    while (cin >> N >> M)
    {
        int diff = 0;
        while (M--)
        {
            int overall;
            cin >> overall;
            
            int his;
            cin >> his;
            
            for (int i = 1; i < N; ++i)
            {
                int other;
                cin >> other;
                overall -= other;
            }
            
            if (his > overall)
                his = 0;
            
            int best = 0;
            for (int i = 0; i < NumCards; ++i)
            {
                if (Cards[i] <= overall)
                {
                    best = Cards[i];
                    break;
                }
            }
            
            diff += best - his;
        }
        
        cout << diff << '\n';
    }
}
