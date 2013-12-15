#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    map<string, string> conversion;
    
    string temp, second;
    getline(cin, temp);
    
    while (temp != "")
    {
        stringstream ss(temp);
        
        ss >> temp >> second;
        
        conversion[second] = temp;
        
        getline(cin, temp);
    }
    
    while (cin >> temp)
    {
        map<string, string>::const_iterator iter = conversion.find(temp);
        
        if (iter == conversion.end())
        
            cout << "eh\n";
        
        else
            cout << iter->second << '\n';
    }
    
}