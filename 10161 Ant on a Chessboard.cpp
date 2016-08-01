#include <algorithm>
#include <iostream>

using namespace std;

const int NumDiagonalNeeded = 44722 + 3;
int diagonalValues[NumDiagonalNeeded];

void MoveAlong(int &primary, int &secondary, int current, int wanted)
{
    int left = wanted - current;
    if (primary - 1 >= left)
        primary -= left;
    else
    {
        primary = left - primary + 1;
        ++secondary;
    }
}

int main()
{
    for (int i = 0; i < NumDiagonalNeeded; ++i)
        diagonalValues[i] = i * i - i + 1;
    
    int N;
    while (cin >> N, N)
    {
        if (N == 2)
        {
            // Behaves differently
            cout << "1 2\n";
            continue;
        }
        
        int *diagonal = lower_bound(diagonalValues + 1, diagonalValues + NumDiagonalNeeded, N);
        
        int diagonalPosition = diagonal - diagonalValues, diagonalVal = *diagonal;
        // May need to do some shifting
        if (diagonalVal != N)
        {
            --diagonalPosition;
            diagonalVal = diagonalValues[diagonalPosition];
        }
        
        int row = diagonalPosition, column = diagonalPosition;
        
        if (diagonalVal != N)
        {
            // Changes the row first
            if (diagonalPosition & 1)
                MoveAlong(row, column, diagonalVal, N);
            else
                MoveAlong(column, row, diagonalVal, N);
        }
        
        cout << row << ' ' << column << '\n';
    }
}