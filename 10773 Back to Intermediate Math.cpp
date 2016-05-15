#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double Eps = 1e-8;

int main()
{
    cout << fixed << setprecision(3);
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int width, riverFlow, boatSpeed;
        
        cin >> width >> riverFlow >> boatSpeed;
        
        cout << "Case " << t << ": ";
        
        if (riverFlow == 0 || riverFlow >= boatSpeed)
        {
            cout << "can't determine\n";
            continue;
        }
        
        
        double fast = 1.0 * width / boatSpeed;
        double angle = asin(1.0 * riverFlow / boatSpeed);
        double otherSpeed = cos(angle) * boatSpeed;
        double slow = width / otherSpeed;
        
        cout << slow - fast << '\n';
    }
}