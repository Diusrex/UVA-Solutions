#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    
    string sep = "";
    
    map<string, int> allCounts;
    while (T--)
    {
        int totalNumber = 0;
        allCounts.clear();
        string line;
        
        while (getline(cin, line) && line != "")
        {
            map<string, int>::iterator iter = allCounts.find(line);
            if (iter == allCounts.end())
                iter = allCounts.insert(pair<string, int>(line, 0)).first;
            
            iter->second += 1;
            ++totalNumber;
        }
        
        cout << sep;
        sep = "\n";
        
        for (map<string, int>::iterator iter = allCounts.begin(); iter != allCounts.end(); ++iter)
        {
            cout << iter->first << ' ' << setprecision(4) << fixed << iter->second * 100.0 / totalNumber << '\n';
        }
    }
}