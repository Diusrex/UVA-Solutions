#include <iostream>
#include <set>

using namespace std;

// Will not access this, other than to print out in the beginning
set<int> baseSets[100005];
int sum[100005];

// Starts off with setAccess[i] = i
int setAccess[100005];

void MergeSets(int valueInA, int valueInB)
{
    // Only handle if they are different
    if (setAccess[valueInA] != setAccess[valueInB])
    {
        int setA = setAccess[valueInA], setB = setAccess[valueInB];
        
        if (baseSets[setA].size() >= baseSets[setB].size())
        {
            sum[setA] += sum[setB];
            baseSets[setA].insert(baseSets[setB].begin(), baseSets[setB].end());
        
            // Update where they are pointing
            for (set<int>::iterator iter = baseSets[setB].begin(); iter != baseSets[setB].end(); ++iter)
            {
                setAccess[*iter] = setA;
            }
        }
        
        else
        {
            sum[setB] += sum[setA];
            baseSets[setB].insert(baseSets[setA].begin(), baseSets[setA].end());
        
            // Update where they are pointing
            for (set<int>::iterator iter = baseSets[setA].begin(); iter != baseSets[setA].end(); ++iter)
            {
                setAccess[*iter] = setB;
            }
        }
    }
}

void MoveBetweenSets(int valueInFrom, int valueInTo)
{
    // Only handle if they are different
    if (setAccess[valueInFrom] != setAccess[valueInTo])
    {
        int from = setAccess[valueInFrom], to = setAccess[valueInTo];
        
        sum[from] -= valueInFrom;
        sum[to] += valueInFrom;
        
        setAccess[valueInFrom] = to;
        
        baseSets[from].erase(valueInFrom);
        baseSets[to].insert(valueInFrom);
    }
}

int main()
{
    int n, m;
    
    while (cin >> n >> m)
    {
        // reset
        for (int i = 1; i <= n; ++i)
        {
            setAccess[i] = i;
            baseSets[i].clear();
            baseSets[i].insert(i);
            sum[i] = i;
        }
        
        while (m--)
        {
            int type, p, q;
            cin >> type;
            if (type == 1)
            {
                cin >> p >> q;
                MergeSets(p, q);
            }
            else if (type == 2)
            {
                cin >> p >> q;
                MoveBetweenSets(p, q);
            }
            else
            {
                cin >> p;
                int index = setAccess[p];
                cout << baseSets[index].size() << ' ' << sum[index] << '\n';
            }
        }
    }
}