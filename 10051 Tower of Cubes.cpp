#include <iostream>

using namespace std;

const int Skipped = 6;

int N;

// Is guy we are at and color
// For best face, use 6 to mean next guy (Skipped)
int numberCanStack[505][105], bestTopFaceToUse[505][105];

// Each cube, 0 and 1 pair, 2 and 3 pair, 4 and 5 pair
// so X pairs with  X^1
int cubes[505][6];

string ToFace(int facePos)
{
    switch (facePos)
    {
    case 0:
        return "front";
    case 1:
        return "back";
    case 2:
        return "left";
    case 3:
        return "right";
    case 4:
        return "top";
    default:
        return "bottom";
    }
}

void PrintOut(int cube, int color)
{
    if (cube == N)
        return;
    
    if (bestTopFaceToUse[cube][color] == Skipped)
    {
        PrintOut(cube + 1, color);
    }
    
    else
    {
        int faceUsed = bestTopFaceToUse[cube][color];
        
        PrintOut(cube + 1, cubes[cube][faceUsed]);
        
        // Their numbering is weird
        cout << (N - cube) << ' ' << ToFace(faceUsed) << '\n';
    }
}

int NumCanStack(int cube, int color)
{
    if (cube == N)
        return 0;
    
    int &num = numberCanStack[cube][color];
    
    if (num == -1)
    {
        num = 0;
        int &bestTopFace = bestTopFaceToUse[cube][color];
        bestTopFace = Skipped;
        
        for (int face = 0; face < 6; ++face)
        {
            if (cubes[cube][face] == color)
            {
                int topFace = face^1;
                int amount = NumCanStack(cube + 1, cubes[cube][topFace]) + 1;
                
                if (amount > num)
                {
                    num = amount;
                    bestTopFace = topFace;
                }
            }
        }
        
        // Attempt to skip
        int amount = NumCanStack(cube + 1, color);
        if (amount > num)
        {
            num = amount;
            bestTopFace = Skipped;
        }
    }
    
    return num;
}

int main()
{
    int T = 1;
    
    while (cin >> N, N)
    {
        // Read them in reverse
        for (int cube = N - 1; cube >= 0; --cube)
        {
            for (int face = 0; face < 6; ++face)
                cin >> cubes[cube][face];
        }
        
        // Clear data
        for (int cube = 0; cube < N; ++cube)
        {
            for (int color = 0; color < 105; ++color)
                numberCanStack[cube][color] = -1;
        }
        
        int bestNum = 0, bestStartCube = -1, bestColor;
        
        for (int cube = 0; cube < N; ++cube)
        {
            // Have this be the 'bottom' face for this guy
            for (int face = 0; face < 6; ++face)
            {
                int num = NumCanStack(cube, cubes[cube][face]);
                if (num > bestNum)
                {
                    bestNum = num;
                    bestStartCube = cube;
                    bestColor = cubes[cube][face];
                }
            }
        }
        
        if (T > 1)
            cout << '\n';
        cout << "Case #" << T++ << '\n';
        cout << bestNum << '\n';
        
        PrintOut(bestStartCube, bestColor);
    }
}