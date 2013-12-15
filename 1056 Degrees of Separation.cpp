#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

const int absoluteMax = 10000;
int main()
{
    int P, R, T(1);
    
    cin >> P;
    while (P)
    {
        cin >> R;
        
        map<string, int> positions;
        
        vector<vector<int> > connectedDist(P, vector<int>(P, absoluteMax));
        
        int pos(0);
        
        for (int i = 0; i < R; ++i)
        {
            string first, second;
            cin >> first >> second;
            
            if (positions.find(first) == positions.end())
            {
                positions[first] = pos++;
            }
            
            int firstPos = positions[first];
            
            if (positions.find(second) == positions.end())
            {
                positions[second] = pos++;
            }
            int secondPos = positions[second];
            
            connectedDist[firstPos][secondPos] = 1;
            connectedDist[secondPos][firstPos] = 1;
        }
        
        
        for (int k = 0; k < P; ++k)
        {
            for (int i = 0; i < P; ++i)
            {
                for (int j = 0; j < P; ++j)
                {
                    connectedDist[i][j] = min(connectedDist[i][j], connectedDist[i][k] + connectedDist[k][j]);
                }
            }
        }
        
        int farthest = 0;
        
        for (int i = 0; i < P; ++i)
        {
            for (int j = i + 1; j < P; ++j)
            {
                farthest = max(connectedDist[i][j], farthest);
            }
        }
        
        cout << "Network " << T++ << ": ";
        
        if (farthest == absoluteMax)
            cout << "DISCONNECTED\n";
        
        else
            cout << farthest << '\n';
        cout << '\n';
        cin >> P;
    }

}