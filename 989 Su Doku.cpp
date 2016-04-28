#include <iostream>

using namespace std;

int n, maxNum;

int grid[9][9];

bool rowInfo[9][10], colInfo[9][10], squareInfo[9][10];

inline int ToSquare(int x, int y)
{
    return (y / n) * n + x / n;
}

bool Fill(int x, int y)
{
    if (x == maxNum)
    {
        ++y;
        if (y == maxNum)
            return true;
        
        return Fill(0, y);
    }
    
    if (grid[y][x] == 0)
    {
        for (int num = 1; num <= maxNum; ++num)
        {
            if (!rowInfo[y][num] && !colInfo[x][num] && !squareInfo[ToSquare(x, y)][num])
            {
                // Try adding this num
                grid[y][x] = num;
                rowInfo[y][num] = colInfo[x][num] = squareInfo[ToSquare(x, y)][num] = true;
                
                if (Fill(x + 1, y))
                    return true;
                
                // Remove it
                grid[y][x] = 0;
                rowInfo[y][num] = colInfo[x][num] = squareInfo[ToSquare(x, y)][num] = false;
            }
        }
        return false;
    }
    else
    {
        return Fill(x + 1, y);
    }
}

int main()
{
    string sep = "";
    
    while (cin >> n)
    {
        cout << sep;
        sep = "\n";
        
        maxNum = n * n;
        
        bool valid = true;
        for (int i = 0; i < maxNum; ++i)
        {
            for (int num = 1; num <= maxNum; ++num)
                rowInfo[i][num] = colInfo[i][num] = squareInfo[i][num] = false;
        }
        
        for (int y = 0; y < maxNum; ++y)
        {
            for (int x = 0; x < maxNum; ++x)
            {
                cin >> grid[y][x];
                if (grid[y][x])
                {
                    int num = grid[y][x];
                    valid &= !(rowInfo[y][num] || colInfo[x][num] || squareInfo[ToSquare(x, y)][num]);
                    valid &= (grid[y][x] <= maxNum);
                    
                    rowInfo[y][num] = colInfo[x][num] = squareInfo[ToSquare(x, y)][num] = true;
                }
            }
        }
        
        if (valid && Fill(0, 0))
        {
            for (int y = 0; y < maxNum; ++y)
            {
                cout << grid[y][0];
                for (int x = 1; x < maxNum; ++x)
                {
                    cout << ' ' << grid[y][x];
                }
                cout << '\n';
            }
        }
        else
        {
            cout << "NO SOLUTION\n";
        }
    }
}