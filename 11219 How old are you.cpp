#include <iostream>
#include <sstream>

using namespace std;

struct myTimeStruct {
    myTimeStruct(string info)
    {
        stringstream ss;
        ss << info;
        char temp;
        ss >> day >> temp;
        ss >> month >> temp;
        ss >> year;
    }
    
    int day, month, year;
};

int main()
{
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        string c, b;
        
        cin >> c >> b;
        
        myTimeStruct current(c), birth(b);
        
        bool isPast = (current.month > birth.month || (current.month == birth.month && current.day >= birth.day));
        
        int yearDiff = current.year - birth.year;
        if (!isPast)
            --yearDiff;
            
        cout << "Case #" << i << ": ";
        
        if (yearDiff < 0)
            cout << "Invalid birth date\n";
        
        else if (yearDiff > 130)
            cout << "Check birth date\n";
        
        else
            cout << yearDiff << '\n';
    }

}