#include <iostream>

using namespace std;

int main()
{
    int numQueries;
    cin >> numQueries;
    
    while (numQueries)
    {
        long xBorder, yBorder;
        cin >> xBorder >> yBorder;
        
        for (int i = 0; i < numQueries; ++i)
        {
            int xSpot, ySpot;
            cin >> xSpot >> ySpot;
            
            if (xSpot == xBorder || ySpot == yBorder)
            {
                cout << "divisa\n";
            }
            
            else if (ySpot > yBorder)
            {
                if (xSpot > xBorder)
                    cout << "NE\n";
                else
                    cout << "NO\n";
            }
            
            else
            {
                if (xSpot > xBorder)
                    cout << "SE\n";
                else
                    cout << "SO\n";
            }
               
        }
        cin >> numQueries;
    }

}