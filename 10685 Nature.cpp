#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

const int UNKNOWN = -1;

int belongingTo[5005];
vector<vector<int> > travelTo(5005);

int connectGroup(int node, int group)
{
    int &nodeGroup = belongingTo[node];
    int count = 0;
    
    if (nodeGroup == UNKNOWN)
    {
        nodeGroup = group;
        for (int i = 0; i < travelTo[node].size(); ++i)
            count += connectGroup(travelTo[node][i], group);
        
        count += 1;
    }
    
    return count;
}

int main()
{
    map<string, int> nameToPos;
    int C, R;
    string n1, n2;
    
    while (cin >> C >> R, C)
    {
        nameToPos.clear();
        
        for (int i = 0; i < C; ++i)
        {
            cin >> n1;
            nameToPos[n1] = i;
            travelTo[i].clear();
            belongingTo[i] = UNKNOWN;
        }
        
        while (R--)
        {
            cin >> n1 >> n2;
            int p1 = nameToPos[n1], p2 = nameToPos[n2];
            travelTo[p1].push_back(p2);
            travelTo[p2].push_back(p1);
        }
        
        int longest = 0;
        
        for (int i = 0; i < C; ++i)
            longest = max(longest, connectGroup(i, i));
        
        cout << longest << '\n';
    }
}