#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

const int TIME_IN_DAY = 1440;
int HR = 60, HALF = 30;

#define t(h) 60 * h
#define th(h) 60 * h + 30

void SetUpMap(map<string, int> & timeChangeInMin)
{
    timeChangeInMin["UTC"] = 0; timeChangeInMin["GMT"] = 0; timeChangeInMin["BST"] = t(1);
    timeChangeInMin["IST"] = t(1); timeChangeInMin["WET"] = 0; timeChangeInMin["WEST"] = t(1);
    timeChangeInMin["CET"] = t(1); timeChangeInMin["CEST"] = t(2); timeChangeInMin["EET"] = t(2);
    timeChangeInMin["EEST"] = t(3); timeChangeInMin["MSK"] = t(3); timeChangeInMin["MSD"] = t(4);
    timeChangeInMin["AST"] = t(-4); timeChangeInMin["ADT"] = t(-3); timeChangeInMin["NST"] = th(-4);
    timeChangeInMin["NDT"] = th(-3); timeChangeInMin["EST"] = t(-5); timeChangeInMin["EDT"] = t(-4);
    timeChangeInMin["CST"] = t(-6); timeChangeInMin["CDT"] = t(-5); timeChangeInMin["MST"] = t(-7);
    timeChangeInMin["MDT"] = t(-6); timeChangeInMin["PST"] = t(-8); timeChangeInMin["PDT"] = t(-7);
    timeChangeInMin["HST"] = t(-10); timeChangeInMin["AKST"] = t(-9); timeChangeInMin["AKDT"] = t(-8);
    timeChangeInMin["AEST"] = t(10); timeChangeInMin["AEDT"] = t(11); timeChangeInMin["ACST"] = th(9);
    timeChangeInMin["ACDT"] = th(10); timeChangeInMin["AWST"] = t(8);
}

int main()
{
    map<string, int> timeChangeInMin;
    SetUpMap(timeChangeInMin);
    
    int T;
    cin >> T;
    
    string from, to, amOrPm;
    while (T--)
    {
        int minutes = 0;
        char character;
        cin >> character;
        
        if (character == 'n')
        {
            // junk
            cin >> from;
            minutes = 12 * 60;
        }
        else if (character == 'm')
        {
            // junk
            cin >> from;
            minutes = 0;
        }
        else
        {
            int hr;
            hr = character - '0';
            char temp;
            cin >> temp;
            if (temp != ':')
            {
                hr = (10 * hr + (temp - '0')) % 12;
                cin >> temp;
            }
            cin >> minutes >> amOrPm;
            minutes += 60 * hr;
            if (amOrPm == "p.m.")
                minutes += 12 * 60;
        }
        
        cin >> from >> to;
        
        
        minutes = (minutes + timeChangeInMin[to] - timeChangeInMin[from] + TIME_IN_DAY) % TIME_IN_DAY;
        
        if (minutes == 12 * 60)
            cout << "noon\n";
        else if (minutes == 0)
            cout << "midnight\n";
        else
        {
            amOrPm = (minutes > 12 * 60 && minutes < 24 * 60) ? "p.m." : "a.m.";
            minutes %= 12 * 60;
            if (minutes / 60 == 0)
                minutes += 12 * 60;
            
            cout << minutes / 60 << ':' << setfill('0') << setw(2) << minutes % 60 << ' ' << amOrPm << '\n';
        }
    }
}