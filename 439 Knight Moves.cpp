#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int SIZE = 8;
const int DIMENSION_SIZE = SIZE * SIZE;

int moves[DIMENSION_SIZE][DIMENSION_SIZE];

bool IsKnightMove(int firstX, int firstY, int secondX, int secondY)
{
    int xAbs = abs(firstX - secondX), yAbs = abs(firstY - secondY);
    
    return (xAbs == 1 && yAbs == 2) || (xAbs == 2 && yAbs == 1);
}

int main()
{
    for (int i = 0; i < DIMENSION_SIZE; ++i)
        for (int j = 0; j < DIMENSION_SIZE; ++j)
        {
            if (i == j)
                moves[i][j] = 0;
            else if (IsKnightMove(i / SIZE, i % SIZE, j / SIZE, j % SIZE))
                moves[i][j] = 1;
            else
                moves[i][j] = 100000;
        }
    
    // Floyd-Warshall
    for (int k = 0; k < DIMENSION_SIZE; ++k)
    {
        for (int i = 0; i < DIMENSION_SIZE; ++i)
        {
            for (int j = 0; j < DIMENSION_SIZE; ++j)
            {
                moves[i][j] = min(moves[i][j], moves[i][k] + moves[k][j]);
            }
        }
    }
    
    string first, second;
    
    while (cin >> first >> second)
    {
        int firstPos = (first[0] - 'a') * SIZE + (first[1] - '1');
        int secondPos = (second[0] - 'a') * SIZE + (second[1] - '1');
        
        cout << "To get from " << first << " to " << second << " takes " << moves[firstPos][secondPos] << " knight moves.\n";
    }
}