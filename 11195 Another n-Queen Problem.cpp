#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int size;
char line[14];
bool placeable[14][14]; // Description lies, is not size 15
int count;

void SearchByRow(int rowNum, int columnTaken, int upDiagonalChallenged, int downDiagonalChallenged)
{
    if (rowNum == size)
    {
        ++count;
        return;
    }
    
    int allBasePossible = ((1 << size) - 1); // Will be all 1 for the rows
    
    int possiblePositions = allBasePossible & ~(columnTaken | upDiagonalChallenged | downDiagonalChallenged);
    for (int c = 0; c < size; ++c)
    {
        if (((possiblePositions >> c) & 1) && placeable[rowNum][c])
        {
            SearchByRow(rowNum + 1, columnTaken | (1 << c), 
                (upDiagonalChallenged | (1 << c)) >> 1, // Add current, then shift down by 1
                (downDiagonalChallenged | (1 << c)) << 1); // Add current, then shift up by 1
        }
    }
}

int main()
{
    int T = 1;
    while (scanf("%d", &size), size)
    {
        for (int i = 0; i < size; ++i)
        {
            scanf("%s", line);
            for (int j = 0; j < size; ++j)
                placeable[i][j] = (line[j] == '.');
        }
        
        count = 0;
        SearchByRow(0, 0, 0, 0);
        
        printf("Case %d: %d\n", T++, count);
    }
}