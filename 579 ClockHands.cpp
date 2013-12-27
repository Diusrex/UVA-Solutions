#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    cout << fixed << setprecision(3);
    
    double hour, minute;
    char temp;
    
    scanf("%lf:%lf",&hour, &minute);
    
    while (hour)
    {
        
        hour += minute / 60.0;
        
        double hourAngle = hour * 30.0;
        double minuteAngle = minute * 6.0;
        
        double diff = abs(hourAngle - minuteAngle);
        
        if (diff > 180)
            diff = 360 - diff;
        
        cout << diff << '\n';
        
        cin >> hour >> temp >> minute;
    }

}