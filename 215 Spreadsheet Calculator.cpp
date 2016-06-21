#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

enum Status
{
    UNKNOWN, CALCULATED, CALCULATING
};

bool currentIsValid;

Status statuses[25][15];
string expressions[25][15];
int value[25][15];

int Calculate(int r, int c)
{
    if (statuses[r][c] == CALCULATED)
    {
        return value[r][c];
    }
    else if (statuses[r][c] == CALCULATING)
    {
        currentIsValid = false;
        return 0;
    }
    
    statuses[r][c] = CALCULATING;
    value[r][c] = 0;
    
    bool isSubtract = false;
    const string& expr = expressions[r][c];
    for (int pos = 0; pos < expr.size(); ++pos)
    {
        // May have trailing blanks
        if (expr[pos] == ' ')
            break;
        
        int toAdd = 0;
        if (expr[pos] == '-')
        {
            isSubtract = true;
            continue;
        }
        else if (expr[pos] == '+')
            continue;
        else if (isdigit(expr[pos]))
        {
            while (pos < expr.size() && isdigit(expr[pos]))
            {
                toAdd = toAdd * 10 + expr[pos] - '0';
                ++pos;
            }
            // To counteract having gone past
            --pos;
        }
        else
        {
            int newR = expr[pos] - 'A';
            ++pos;
            int newC = expr[pos] - '0';
            
            toAdd = Calculate(newR, newC);
            
            if (!currentIsValid)
            {
                return 0;
            }
        }
        
        if (isSubtract)
            toAdd *= -1;
        value[r][c] += toAdd;
        isSubtract = false;
    }
    
    statuses[r][c] = CALCULATED;
    return value[r][c];
}

int main()
{
    int R, C;
    while (cin >> R >> C, R)
    {
        cin.ignore();
        
        for (int r = 0; r < R; ++r)
        {
            for(int c = 0; c < C; ++c)
            {
                getline(cin, expressions[r][c]);
                statuses[r][c] = UNKNOWN;
            }
        }
        
        bool overallIsValid = true;
        for (int r = 0; r < R; ++r)
        {
            for(int c = 0; c < C; ++c)
            {
                currentIsValid = true;
                
                Calculate(r, c);
                overallIsValid &= currentIsValid;
            }
        }
        
        if (overallIsValid)
        {
            cout << " ";
            for (int c = 0; c < C; ++c)
            {
                cout << setw(6) << c;
            }
            cout << '\n';
            
            for (int r = 0; r < R; ++r)
            {
                cout << char('A' + r);
                
                for (int c = 0; c < C; ++c)
                {
                    cout << setw(6) << value[r][c];
                }
                cout << '\n';
            }
        }
        else
        {
            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    if (statuses[r][c] == CALCULATING)
                        cout << char('A' + r) << c << ": " << expressions[r][c] << '\n';
                }
            }
        }
        
        cout << '\n';
    }
}