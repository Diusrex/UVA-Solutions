#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct NumberInfo
{
    int num;
    vector<int> allPositions;
    
    bool operator<(const NumberInfo & other) const
    {
        return num < other.num;
    }
    
    NumberInfo(int num)
        : num(num)
    {}
};

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        map<int, NumberInfo> numberMap;
        map<int, NumberInfo>::iterator iter;
        
        int num;
        
        for (int i = 1; i <= n; ++i)
        {
            cin >> num;
            if ((iter = numberMap.find(num)) == numberMap.end())
                iter = numberMap.insert(std::pair<int, NumberInfo>(num, NumberInfo(num))).first;
            
            iter->second.allPositions.push_back(i);
        }
        
        int pos;
        while (m--)
        {
            cin >> pos >> num;
            --pos;
            iter = numberMap.find(num);
            
            if (iter == numberMap.end() || iter->second.allPositions.size() <= pos)
                cout << "0\n";
            else
                cout << iter->second.allPositions[pos] << '\n';
        }
    }
}