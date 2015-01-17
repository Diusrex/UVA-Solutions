#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > gcds(501, vector<int>(501, 0));

int gcd(int x, int y)
{
    int &g = gcds[x][y];
    if (g == 0)
    {
        if (x == 0)
            g = y;
        else
            g = gcd(y % x, x);
        gcds[y][x] = g;
    }
    
    return g;
}

int GetG(int n)
{
    int G = 0;
    for(int i= 1; i < n; ++i)
        for(int j= i + 1; j <= n; ++j)
            G += gcd(i, j);

    return G;
}

int main()
{
    int n;
    
    while (scanf("%d", &n), n)
        printf("%d\n", GetG(n));
}