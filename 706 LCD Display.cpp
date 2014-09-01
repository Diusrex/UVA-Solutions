#include <iostream>
#include <string>
#include <vector>

using namespace std;

// will be:
//   0
// 1 2 3
// 4 5 6
// ex: 1 is only 3 and 6 are true
//                              0      1      2      3      4      5      6
bool placesToPrint[10][7] = {{ true,  true, false,  true,  true,  true,  true}, // 0
                             {false, false, false,  true, false, false,  true}, // 1
                             { true, false,  true,  true,  true,  true, false}, // 2
                             { true, false,  true,  true, false,  true,  true}, // 3
                             {false,  true,  true,  true, false, false,  true}, // 4
                             { true,  true,  true, false, false,  true,  true}, // 5
                             { true,  true,  true, false,  true,  true,  true}, // 6
                             { true, false, false,  true, false, false,  true}, // 7
                             { true,  true,  true,  true,  true,  true,  true}, // 8
                             { true,  true,  true,  true, false,  true,  true}}; // 9

void PrintRow(const vector<int>& digits, const string & usedRow, const string & blankRow, int pos)
{
    for (int i = 0; i < digits.size(); ++i)
    {
        if (i)
            cout << ' ';
        cout << ' ' << (placesToPrint[digits[i]][pos] ? usedRow : blankRow) << ' ';
    }
    cout << '\n';
}

void PrintColumn(const vector<int> & digits, const string & blankRow, int posL, int posR)
{
    for (int i = 0; i < digits.size(); ++i)
    {
        if (i)
            cout << ' ';

        cout << (placesToPrint[digits[i]][posL] ? '|' : ' ') << blankRow << (placesToPrint[digits[i]][posR] ? '|' : ' ');
    }
    
    cout << '\n';
}

void PrintOut(const vector<int>& digits, int size)
{
    string usedRow(size, '-');
    string blankRow(size, ' ');
    
    PrintRow(digits, usedRow, blankRow, 0);
    
    for (int i = 0; i < size; ++i)
        PrintColumn(digits, blankRow, 1, 3);
    PrintRow(digits, usedRow, blankRow, 2);
    
    for (int i = 0; i < size; ++i)
        PrintColumn(digits, blankRow, 4, 6);
    PrintRow(digits, usedRow, blankRow, 5);
}

int main()
{
    int size;
    string n;
    vector<int> digits;
    
    while (cin >> size >> n, size)
    {
        digits.resize(n.size());
        for (int i = 0; i < digits.size(); ++i)
            digits[i] = n[i] - '0';
            
        PrintOut(digits, size);
        
        cout << '\n';
    }
}