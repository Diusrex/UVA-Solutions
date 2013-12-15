#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int courseNumber;
    
    cin >> courseNumber;
    
    while (courseNumber != 0)
    {
        int m;
        cin >> m;
        
        vector<vector<vector<vector<bool> > > > isTaken(10, vector<vector<vector<bool> > >(10, vector<vector<bool> >(10, vector<bool> (10, false))));
        
        for (int i = 0; i < courseNumber; ++i)
        {
            int temp;
            cin >> temp;
            isTaken[temp/1000][(temp/100)%10][(temp/10)%10][temp%10] = true;
        }
        
        bool allAreTrue(true);
        
        for (int i = 0; i < m; ++i)
        {
            int numberOfOptions, numberRequired;
            cin >> numberOfOptions >> numberRequired;
            
            int numberOfMatches(0);
            
            for (int z = 0; z < numberOfOptions; ++z)
            {
                int current;
                cin >> current;
                
                if (isTaken[current/1000][(current/100)%10][(current/10)%10][current%10])
                    ++numberOfMatches;
            }
            
            if (numberOfMatches < numberRequired)
                allAreTrue = false;
                
        }
        
        if (allAreTrue)
            cout << "yes\n";
        else
            cout << "no\n";
            
        cin >> courseNumber;
    }

}