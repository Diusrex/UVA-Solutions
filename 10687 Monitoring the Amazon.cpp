#include <iostream>
#include <algorithm>

using namespace std;


const int MaxNum = 1005;

struct Point
{
    int x, y;
    
    bool operator<(const Point & other) const
    {
        if (x != other.x)
            return x < other.x;
        
        return y < other.y;
    }
};

Point points[MaxNum];

int twoNeighbors[MaxNum][2];
bool reached[MaxNum];

int N;

inline int Square(int num)
{
    return num * num;
}

void FindClosestForAll()
{
    for (int i = 0; i < N; ++i)
    {
        int &first = twoNeighbors[i][0], &second = twoNeighbors[i][1];
        first = second = -1;
        int firstSqDist, secondSqDist;
        
        for (int j = 0; j < N; ++j)
        {
            if (i != j)
            {
                int sqDistance = Square(points[i].x - points[j].x) + Square(points[i].y - points[j].y);
                if (first == -1 || firstSqDist > sqDistance)
                {
                    second = first;
                    secondSqDist = firstSqDist;
                    
                    first = j;
                    firstSqDist = sqDistance;
                }
                else if (second == -1 || secondSqDist > sqDistance)
                {
                    second = j;
                    secondSqDist = sqDistance;
                }
            }
        }
    }
}

int dfs(int node)
{
    if (node == -1 || reached[node])
        return 0;
    
    reached[node] = true;
    
    
    return 1 + dfs(twoNeighbors[node][0]) + dfs(twoNeighbors[node][1]);
}


int main()
{
    while (cin >> N, N)
    {
        for (int i = 0; i < N; ++i)
            cin >> points[i].x >> points[i].y;
        
        Point station = points[0];
        
        sort(points, points + N);
        
        FindClosestForAll();
        
        for (int i = 0; i < N; ++i)
            reached[i] = false;
        
        bool valid = false;
        for (int i = 0; i < N; ++i)
        {
            if (station.x == points[i].x && station.y == points[i].y)
            {
                valid = (dfs(i) == N);
            }
        }
        
        if (valid)
            cout << "All stations are reachable.\n";
        else
            cout << "There are stations that are unreachable.\n";
    }
}