#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> order;
    map<int, int> numOccurances;
    map<int, int>::iterator iter;
    
    int num;
    
    while (cin >> num)
    {
        iter = numOccurances.find(num);
        
        if (iter == numOccurances.end())
        {
            order.push_back(num);
            numOccurances[num] = 1;
        }
        else
            ++(iter->second);
    }
    
    for (int i = 0; i < order.size(); ++i)
    {
        cout << order[i] << ' ' << numOccurances[order[i]] << '\n';
    }
}