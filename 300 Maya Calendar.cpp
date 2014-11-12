#include <iostream>
#include <string>

using namespace std;

int GetNumberMonthsBefore(const string & month)
{
    if (month == "pop")
        return 0;
    else if (month == "no")
        return 1;
    else if (month == "zip")
        return 2;
    else if (month == "zotz")
        return 3;
    else if (month == "tzec")
        return 4;
    else if (month == "xul")
        return 5;
    else if (month == "yoxkin")
        return 6;
    else if (month == "mol")
        return 7;
    else if (month == "chen")
        return 8;
    else if (month == "yax")
        return 9;   
    else if (month == "zac")
        return 10;
    else if (month == "ceh")
        return 11;
    else if (month == "mac")
        return 12;
    else if (month == "kankin")
        return 13;
    else if (month == "muan")
        return 14;
    else if (month == "pax")
        return 15;
    else if (month == "koyab")
        return 16;  
    else if (month == "cumhu")
        return 17;
    else // uayet 
        return 18;
}

string ToMonth(int numDaysIntoSequence)
{
    switch (numDaysIntoSequence)
    {
    case 0:
        return "imix";
    case 1:
        return "ik";
    case 2:
        return "akbal";
    case 3:
        return "kan";
    case 4:
        return "chicchan";
    case 5:
        return "cimi";
    case 6:
        return "manik";
    case 7:
        return "lamat";
    case 8:
        return "muluk";
    case 9:
        return "ok";
    case 10:
        return "chuen";
    case 11:
        return "eb";
    case 12:
        return "ben";
    case 13:
        return "ix";
    case 14:
        return "mem";
    case 15:
        return "cib";
    case 16:
        return "caban";
    case 17:
        return "eznab";
    case 18:
        return "canac";
    default:
        return "ahau";
    }
}

int main()
{
    int T;
    cin >> T;
    cout << T << '\n';
    
    while (T--)
    {
        int numberOfDays, year;
        char temp;
        string month;
        
        cin >> numberOfDays >> temp >> month >> year;
        
        numberOfDays += GetNumberMonthsBefore(month) * 20;
        numberOfDays += 365 * year;
        
        year = numberOfDays / 260;
        
        cout << numberOfDays % 13 + 1 << ' ' << ToMonth(numberOfDays % 20) << ' ' << year << '\n';
    }
}