#include <iostream>
#include <cmath>

using namespace std;

struct Rectangle
{
    double left, top;
    double right, bottom;
    
    bool IsInside(double x, double y)
    {
        return x > left && x < right
            && y > bottom && y < top;
    }
};

Rectangle recs[10000];

int main()
{
    int numRecs = 0;
    
    char id;
    
    while (cin >> id, id == 'r')
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        recs[numRecs].left = min(x1, x2);
        recs[numRecs].right = max(x1, x2);
        recs[numRecs].bottom = min(y1, y2);
        recs[numRecs].top = max(y1, y2);
        ++numRecs;
    }
    
    double x, y;
    int numPoints = 1;
    
    while (cin >> x >> y, fabs(x - 9999.9) > 1e-6  && fabs(y - 9999.9) > 1e-6)
    {
        bool insideAny = false;
        for (int i = 0; i < numRecs; ++i)
            if (recs[i].IsInside(x, y))
            {
                cout << "Point " << numPoints << " is contained in figure " << (i + 1) << "\n";
                insideAny = true;
            }
         
        if (!insideAny)
            cout << "Point " << numPoints << " is not contained in any figure\n";
        
        ++numPoints;
    }
}