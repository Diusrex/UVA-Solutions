#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for (int t = 0; t < N; ++t)
    {
        int L;
        cin >> L;
        
        vector<int> order(L);
        
        for (int i = 0; i < L; ++i)
            cin >> order[i];
            
        int count(0);
        
        for (int i = 0; i < L; ++i)
        {
            for (int z = i; z > 0 && order[z] < order[z - 1]; --z)
            {
                ++count;
                int temp(order[z]);
                order[z] = order[z - 1];
                order[z - 1] = temp;
            }
        }
        
        cout << "Optimal train swapping takes " << count << " swaps.\n";
    
    
    }

}