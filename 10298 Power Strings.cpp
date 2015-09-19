#include <iostream>
#include <string>

using namespace std;

// Use KMP to get the decrease used
    
int T[1000005];

void ComputeSpecialKMPTable(const string & n)
{
    int size = n.size();
    T[0] = -1;
    T[1] = 0;
    int pos = 2;
    int cnd = 0;
    
    while (pos < size)
    {
        if (n[pos - 1] == n[cnd])
        {
            cnd = cnd + 1;
            T[pos] = cnd;
            ++pos;
        }
        
        else if (cnd > 0)
        {
            cnd = T[cnd];
        }
        
        else
        {
            T[pos] = 0;
            ++pos;
        }
    }
}

int main()
{
    string n;
    while (cin >> n, n.find('.') == string::npos)
    {
        ComputeSpecialKMPTable(n);
        
        int startIndex = n.size() - 1;
        int finalIndex = T[startIndex];
        
        if (finalIndex != -1 && n[finalIndex] != n[startIndex])
            finalIndex = min(0, finalIndex - 1); // Need to handle when it should actually be full length of string
        
        int jump = startIndex - finalIndex;
        
        cout << (n.size() / jump) << '\n';
    }
}