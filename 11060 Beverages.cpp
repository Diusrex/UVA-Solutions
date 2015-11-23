#include <iostream>
#include <bitset>
#include <map>

using namespace std;

string names[105];

int N;

// if [a][b] is true, b must be before a
bitset<105> printed;
bitset<105> onesAfter[105];

// Don't do this as a graph because of the requirement that ones with no relation
// be printed in order given in input.
void PrintNext()
{
    for (int i = 0; i < N; ++i)
    {
        // Every in onesAfter has been done in onesAfter
        if (!printed[i] && (printed & onesAfter[i]) == onesAfter[i])
        {
            cout << ' ' << names[i];
            printed[i] = true;
            return;
        }
    }
}

int main()
{
    int t = 1;
    while (cin >> N)
    {
        map<string, int> nameToPos;
        
        for (int i = 0; i < N; ++i)
        {
            cin >> names[i];
            nameToPos[names[i]] = i;
            printed[i] = false;
            onesAfter[i] = 0;
        }
        
        int M;
        cin >> M;
        
        while (M--)
        {
            string a, b;
            cin >> a >> b;
            
            onesAfter[nameToPos[b]][nameToPos[a]] = 1;
        }
        
        cout << "Case #" << t++ << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < N; ++i)
        {
            PrintNext();
        }
        
        cout << ".\n\n";
    }
}