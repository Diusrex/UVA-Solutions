#include <iostream>

using namespace std;

// [y][x]
bool taken[505][505];

int main()
{
    int W, H, N;
    while (cin >> W >> H >> N, W)
    {
        while (N--)
        {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;
            if (X1 > X2)
                swap(X1, X2);
            if (Y1 > Y2)
                swap(Y1, Y2);
            for (int y = Y1 - 1; y < Y2; ++y)
                for (int x = X1 - 1; x < X2; ++x)
                    taken[y][x] = true;
        }
        int count = 0;
        
        for (int y = 0; y < H; ++y)
        {
            for (int x = 0; x < W; ++x)
            {
                if (!taken[y][x])
                    ++count;
                else
                    taken[y][x] = false;
            }
        }
        if (count == 0)
            cout << "There is no empty spots.\n";
        else if (count == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << count << " empty spots.\n";
    }
}