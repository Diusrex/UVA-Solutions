#include <iostream>
#include <vector>

using namespace std;

vector<int> includedInGroup[100000];
int group[100000];

void Merge(int c1, int c2)
{
    int c1Group = group[c1], c2Group = group[c2];
    if (c1Group == c2Group)
        return;
    
    int changedGroup, keptGroup;
    if (includedInGroup[c1Group].size() >= includedInGroup[c2Group].size())
    {
        changedGroup = c2Group;
        keptGroup = c1Group;
    }
    else
    {
        changedGroup = c1Group;
        keptGroup = c2Group;
    }
    
    for (int i = 0; i < includedInGroup[changedGroup].size(); ++i)
    {
        const int comp = includedInGroup[changedGroup][i];
        includedInGroup[keptGroup].push_back(comp);
        group[comp] = keptGroup;
    }
}

int main()
{
    int T;
    cin >> T;
    string sep = "";
    while (T--)
    {
        cout << sep;
        sep = "\n";
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            includedInGroup[i].assign(1, i);
            group[i] = i;
        }
        cin.ignore();
        int sucess = 0, fail = 0;
        
        while (cin.peek() == 'c' || cin.peek() == 'q')
        {
            int c1, c2;
            char query;
            cin >> query >> c1 >> c2;
            cin.ignore();
            --c1; --c2;
            if (query == 'q')
            {
                if (group[c1] == group[c2])
                    ++sucess;
                else
                    ++fail;
            }
            else
            {
                Merge(c1, c2);
            }
        }
        
        cout << sucess << ',' << fail << '\n';
    }
}