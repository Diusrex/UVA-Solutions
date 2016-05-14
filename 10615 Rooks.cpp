#include <iostream>

using namespace std;

const int Unconnected = -1;
const int NoColor = 0;

int N;
int numColors;

// From row to column
int connections[105][105];
int rowColorsUsed[105][101], columnColorsUsed[105][101];

void PushColorAlong(int r, int c, int takenColor, int replacedColor, bool fromRow)
{
    // Update the color first
    connections[r][c] = takenColor;
    int nextNode;
    // Will first need to remove taken color from the outer one
    if (fromRow)
        nextNode = columnColorsUsed[c][takenColor];
    else
        nextNode = rowColorsUsed[r][takenColor];
    
    
    if (nextNode != -1)
    {
        if (fromRow)
            PushColorAlong(nextNode, c, replacedColor, takenColor, false);
        else
            PushColorAlong(r, nextNode, replacedColor, takenColor, true);
    }
    else
    {
        if (fromRow)
            columnColorsUsed[c][replacedColor] = -1;
        else
            rowColorsUsed[r][replacedColor] = -1;
    }
    
    rowColorsUsed[r][takenColor] = c;
    columnColorsUsed[c][takenColor] = r;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        
        string line;
        
        int rowCount[105], columnCount[105];
        
        for (int i = 0; i < N; ++i)
            rowCount[i] = columnCount[i] = 0;
        
        numColors = 0;
        for (int r = 0; r < N; ++r)
        {
            cin >> line;
            for (int c = 0; c < N; ++c)
            {
                if (line[c] == '*')
                {
                    ++rowCount[r];
                    ++columnCount[c];
                    connections[r][c] = NoColor;
                }
                else
                    connections[r][c] = Unconnected;
            }
        }
        
        for (int i = 0; i < N; ++i)
            numColors = max(numColors, max(rowCount[i], columnCount[i]));
        
        // Reset colors
        for (int i = 0; i < N; ++i)
        {
            for (int color = 1; color <= numColors; ++color)
                rowColorsUsed[i][color] = columnColorsUsed[i][color] = -1;
        }
        
        for (int r = 0; r < N; ++r)
        {
            // For each guy it is connected to, try to set the color
            for (int c = 0; c < N; ++c)
            {
                if (connections[r][c] == NoColor)
                {
                    // Find a common color
                    int rowCommon = -1, columnCommon = -1;
                    for (int color = 1; color <= numColors; ++color)
                    {
                        if (rowColorsUsed[r][color] == -1 && columnColorsUsed[c][color] == -1)
                            rowCommon = columnCommon = color;
                        
                        if (rowColorsUsed[r][color] == -1 && rowCommon == -1)
                            rowCommon = color;
                        if (columnColorsUsed[c][color] == -1 && columnCommon == -1)
                            columnCommon = color;
                    }
                    
                    // Super easy
                    if (rowCommon == columnCommon)
                    {
                        connections[r][c] = rowCommon;
                        rowColorsUsed[r][rowCommon] = c;
                        columnColorsUsed[c][rowCommon] = r;
                    }
                    else
                    {
                        // Push the rowCommon along the columns
                        PushColorAlong(columnColorsUsed[c][rowCommon], c, columnCommon, rowCommon, false);
                        
                        connections[r][c] = rowCommon;
                        rowColorsUsed[r][rowCommon] = c;
                        columnColorsUsed[c][rowCommon] = r;
                    }
                }
            }
        }
        
        cout << numColors << '\n';
        for (int r = 0; r < N; ++r)
        {
            cout << ((connections[r][0] == Unconnected) ? 0 : connections[r][0]);
            for (int c = 1; c < N; ++c)
            {
                cout << ' ' << ((connections[r][c] == Unconnected) ? 0 : connections[r][c]);
            }
            cout << '\n';
        }
    }
}