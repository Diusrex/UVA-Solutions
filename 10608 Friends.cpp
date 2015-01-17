#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > allFriends;

int GetNumFriends(int person, vector<bool>& reached)
{
    if (reached[person])
        return 0;
    
    reached[person] = true;
    
    int sum = 1;
    for (int i = 0; i < allFriends[person].size(); ++i)
        sum += GetNumFriends(allFriends[person][i], reached);
    return sum;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        ++n;
        allFriends.assign(n, vector<int>());
        
        while (m--)
        {
            int start, end;
            cin >> start >> end;
            allFriends[start].push_back(end);
            allFriends[end].push_back(start);
        }
        
        
        vector<bool> reached(n, false);
        int max = 1;
        for (int i = 0; i < n; ++i)
        {
            int current = GetNumFriends(i, reached);
            if (current > max)
                max = current;
        }
        
        cout << max << '\n';
    }
}