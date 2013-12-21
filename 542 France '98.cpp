#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    vector<string> names(16);
    
    for (int i = 0; i < 16; ++i)
        cin >> names[i];
        
    vector<vector<double> > beatChance(16, vector<double>(16));
    
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
        {   
            cin >> beatChance[i][j];
            beatChance[i][j] /= 100;
        }
            
    vector<double> probabilityOld(16, 1);
    vector<double> probabilityNew(16);  
    
    for (int round = 0, groupSize = 1; round < 4; ++round, groupSize *= 2)
    {
        for (int i = 0; i < 16; ++i)
        {
            int currentG = i / groupSize;
            
            int start;
            if (currentG % 2 == 0)
                start = currentG * groupSize + groupSize;
            else
                start = currentG * groupSize - groupSize;
            
            probabilityNew[i] = 0;
            
            for (int x = 0; x < groupSize; ++x)
                probabilityNew[i] += probabilityOld[start + x] * beatChance[i][start + x];
            
            probabilityNew[i] *= probabilityOld[i];
        }
        
        probabilityOld = probabilityNew;
    }

    cout << setprecision(2) << fixed << std::left;
    
    for (int i = 0; i < 16; ++i)
    {
        probabilityOld[i] *= 100;
        cout << setw(10) << names[i] << " p=" << probabilityOld[i] << "%\n";
    }
}