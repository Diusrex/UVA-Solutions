#include <iostream>
#include <bitset>

using namespace std;

const int NumColumns = 5;
const int NumRows = 6;
bitset<26> MayBeInColumn[NumColumns];

int targetSolution, numSolutions;
int Solution[NumColumns];

bool GetSolution(int column)
{
    if (column == NumColumns)
    {
        ++numSolutions;
        return targetSolution == numSolutions;
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (MayBeInColumn[column][i])
        {
            Solution[column] = i;
            if (GetSolution(column + 1))
                return true;
        }
    }
    
    return false;
}

void ReadInForArray(bitset<26>* mayBeInColumn)
{
    for (int r = 0; r < NumRows; ++r)
    {
        string row;
        cin >> row;
        for (int c = 0; c < NumColumns; ++c)
        {
            mayBeInColumn[c][row[c] - 'A'] = true;
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> targetSolution;
        numSolutions = 0;
        for (int c = 0; c < NumColumns; ++c)
            MayBeInColumn[c] = 0;
        
        ReadInForArray(MayBeInColumn);
        bitset<26> otherInColumn[NumColumns];
        ReadInForArray(otherInColumn);
        for (int c = 0; c < NumColumns; ++c)
            MayBeInColumn[c] &= otherInColumn[c];
        
        if (GetSolution(0))
        {
            for (int c = 0; c < NumColumns; ++c)
                cout << static_cast<char>('A' + Solution[c]);
            cout << '\n';
        }
        else
            cout << "NO\n";
    }
    
}