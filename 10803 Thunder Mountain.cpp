#include <cstdio>
#include <cmath>
#include <algorithm>

const int MaxSquaredDistance = 10 * 10;

// Far larger than actual
const double INF = 1024 * 101;
const double POSSIBLE_MARGIN = INF - 1;

int xLocation[101];
int yLocation[101];
double distance[101][101];

int SquaredDistance(int firstTown, int secondTown)
{
    int xDiff = xLocation[firstTown] - xLocation[secondTown];
    int yDiff = yLocation[firstTown] - yLocation[secondTown];
    
    return xDiff * xDiff + yDiff * yDiff;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        int N;
        scanf("%d", &N);
        
        for (int i = 0; i < N; ++i)
            scanf("%d%d", xLocation + i, yLocation + i);
        
        for (int first = 0; first < N; ++first)
        {
            for (int second = first + 1; second < N; ++second)
            {
                int squaredDist = SquaredDistance(first, second);
                if (squaredDist <= MaxSquaredDistance)
                {
                    double dist = sqrt(squaredDist);
                    distance[first][second] = dist;
                    distance[second][first] = dist;
                }
                else
                {
                    distance[first][second] = INF;
                    distance[second][first] = INF;
                }
            }
        }
        
        
        for (int k = 0; k < N; ++k)
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        double maximum = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                maximum = std::max(maximum, distance[i][j]);
            }
        }
        printf("Case #%d:\n", t);
        if (maximum > POSSIBLE_MARGIN)
            printf("Send Kurdy\n\n");
        else
            printf("%.4f\n\n", maximum);
    }
}