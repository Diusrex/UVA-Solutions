#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    map<string, int> count;
    
    while (n--)
    {   
        string country;
        cin >> country;
        
        string temp;
        getline(cin, temp);

        count[country] += 1;    
    }
    
    for (map<string, int>::const_iterator iter = count.begin(); iter != count.end(); ++iter)
        cout << iter->first << " " << iter->second << '\n';
    

}