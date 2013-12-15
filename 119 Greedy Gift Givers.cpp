#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main()
{
    string seperator = "";
    int N;
    while (cin >> N)
    {
        
        vector<string> names;
        vector<int> moneys;
        
        map<string, int> eachPosition;
        
        for (int i = 0; i < N; ++i)
        {
            string temp;
            cin >> temp;
            eachPosition[temp] = i;
            
            names.push_back(temp);
            moneys.push_back(0);
            
        }
        
        for (int i = 0; i < N; ++i)
        {
            string giver;
            cin >> giver;
            
            int money, peopleNum;
            cin >> money >> peopleNum;
            
            if (peopleNum != 0)
            {
                money -= money % peopleNum;
            
                moneys[eachPosition[giver]] -= money;
            
                for (int z = 0; z < peopleNum; ++z)
                {
                    string name;
                    cin >> name;
                    
                    moneys[eachPosition[name]] += money / peopleNum;   
                }
            }
        }
        cout << seperator;
        seperator = "\n";
        
        for (int i = 0; i < N; ++i)
            cout << names[i] << " " << moneys[i] << '\n';
    }

}