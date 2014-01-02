#include <iostream>

using namespace std;

int main()
{
    int n, lowest, previousRest, previousDrug;
    
    bool reachedRest, reachedDrug;
    
    string highway;
    
    while (cin >> n, n)
    {
        cin >> highway;
        
        previousRest = previousDrug = lowest = -1;
        reachedRest = reachedDrug = false;
        
        
        for (string::iterator iter = highway.begin(); iter != highway.end(); ++iter, ++previousRest, ++previousDrug)
        {
            if (*iter == 'Z')
                lowest = 0;
            
            else if (*iter == 'R')
            {
                if (reachedDrug && (previousDrug < lowest || lowest == -1))
                        lowest = previousDrug;
                
                
                reachedRest = true;
                
                previousRest = 0;
            }
            
            else if (*iter == 'D')
            {
                if (reachedRest && (previousRest < lowest || lowest == -1))
                    lowest = previousRest;
                    
                reachedDrug = true;
                
                previousDrug = 0;
            }
        }
        
        cout << lowest << '\n';
    }
}