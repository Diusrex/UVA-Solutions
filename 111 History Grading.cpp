#include <iostream>
#include <algorithm>

using namespace std;

int ranking[30];
int studentRanking[30];
int contiguous[30];

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> ranking[i];
    }
    
    int temp;
    
    while (cin >> temp)
    {
        studentRanking[temp] = ranking[0];
        
        for (int i = 1; i < N; ++i)
        {
            cin >> temp;
            studentRanking[temp] = ranking[i];
        }
        
        int best = 0;
        
        for (int i = 1; i <= N; ++i)
        {
            int & current = contiguous[i] = 0;
            
            for (int j = i - 1; j >= 0; --j)
            {
                if (studentRanking[j] < studentRanking[i] && contiguous[j] > current)
                    current = contiguous[j];
            }
            
            ++current;
            
            if (current > best)
                best = current;
        }
        
        cout << best << '\n';
    }
}