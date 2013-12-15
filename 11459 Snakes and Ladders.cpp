#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        vector<int> playerPositions(a, 1), changeFromSpot(101, 0);
        
        for (int z = 0; z < b; ++z)
        {
            int start, end;
            cin >> start >> end;
            
            changeFromSpot[start] = end - start;
        }
        
        bool won(false);
        
        int change;
        
        for (int z = 0; z < c; ++z)
        {
            cin >> change;
            if (!won)
            {
                playerPositions[z % a] += change;
                
                while (playerPositions[z % a] < 100 && changeFromSpot[playerPositions[z % a]] != 0)
                    playerPositions[z % a] += changeFromSpot[playerPositions[z % a]];
                
                
                if (playerPositions[z % a] >= 100)
                    won = true;
            }
        }
        
        for (int i = 0; i < a; ++i)
            cout << "Position of player " << i + 1 << " is " << playerPositions[i] << ".\n";
    
    }

}