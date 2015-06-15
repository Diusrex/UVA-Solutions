#include <iostream>

using namespace std;

const int NONE = -1;

int rows[123], columns[123];

int main()
{
    int dimen;
    while (cin >> dimen, dimen)
    {
        for (int i = 0; i < dimen; ++i)
            rows[i] = columns[i] = 0;
        
        int num;
        for (int r = 0; r < dimen; ++r)
        {
            for (int c = 0; c < dimen; ++c)
            {
                cin >> num;
                rows[r] += num;
                columns[c] += num;
            }
        }
        
        int invalidRow = NONE, invalidColumn = NONE;
        
        bool valid = true;
        
        for (int i = 0; i < dimen; ++i)
        {
            if (rows[i] & 1)
            {
                if (invalidRow == NONE)
                    invalidRow = i;
                else
                {
                    valid = false;
                    break;
                }
            }
            
            if (columns[i] & 1)
            {
                if (invalidColumn == NONE)
                    invalidColumn = i;
                else
                {
                    valid = false;
                    break;
                }
            }
        }
        
        if (!valid)
            cout << "Corrupt\n";
        else if (invalidRow != NONE)
            cout << "Change bit (" << (invalidRow + 1) << "," << (invalidColumn + 1) << ")\n";
        else
            cout << "OK\n";
    }
}