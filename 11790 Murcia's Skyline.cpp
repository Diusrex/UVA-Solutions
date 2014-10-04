#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    vector<int> height;
    vector<int> width;
    vector<int> ascendingWidth;
    vector<int> descendingWidth;
    
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        
        height.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> height[i];
         
        width.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> width[i];
            
        ascendingWidth.resize(N);
        descendingWidth.resize(N);
        
        int ascending = 0, descending = 0;
        
        for (int i = 0; i < N; ++i)
        {
            int & currentAscending = ascendingWidth[i] = 0;
            int & currentDescending = descendingWidth[i] = 0;
            
            for (int j = 0; j < i; ++j)
            {
                if (height[j] < height[i] && currentAscending < ascendingWidth[j])
                    currentAscending = ascendingWidth[j];
                
                if (height[j] > height[i] && currentDescending < descendingWidth[j])
                    currentDescending = descendingWidth[j];
            }
            
            currentAscending += width[i];
            currentDescending += width[i];
            
            if (ascending < currentAscending)
                ascending = currentAscending;
            if (descending < currentDescending)
                descending = currentDescending;
        }
        
        if (ascending >= descending)
            cout << "Case " << t << ". Increasing (" << ascending << "). Decreasing (" << descending << ").\n";
        else
            cout << "Case " << t << ". Decreasing (" << descending << "). Increasing (" << ascending << ").\n";
            
    }
}