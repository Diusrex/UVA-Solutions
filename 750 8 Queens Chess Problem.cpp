#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

inline bool NotAttacking(int rowVals[])
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (i + rowVals[i] == j + rowVals[j]
                || i - rowVals[i] == j - rowVals[j])
                return false;
        }
    }
    
    return true;
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
        int reqRow, reqCol;
        cin >> reqRow >> reqCol;
        
        --reqCol; // Easier to have it be 0 indexed
        int numSols = 0;
        int rowVals[] = {1, 2, 3, 4, 5, 6, 7, 8};
        
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        
        do
        {
            if (rowVals[reqCol] == reqRow && NotAttacking(rowVals))
            {
            
                cout << setw(2) << ++numSols << "     ";
                for (int i = 0; i < 8; ++i)
                    cout << ' ' << rowVals[i];
                cout << '\n';
            }
            
        } while (next_permutation(rowVals, rowVals + 8));
    }
}
