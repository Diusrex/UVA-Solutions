#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edges[1005];
int number[1005];

void BreadthPush(int N)
{
    queue<int> frontier;
    frontier.push(0);
    number[0] = 0;
    for (int i = 1; i < N; ++i)
        number[i] = N + 2;
    
    while (!frontier.empty())
    {
        int next = frontier.front();
        frontier.pop();
        
        int nextCost = number[next] + 1;
        for (int i = 0; i < edges[next].size(); ++i)
        {
            int to = edges[next][i];
            if (number[to] > nextCost)
            {
                number[to] = nextCost;
                frontier.push(to);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    string sep = "";
    while (T--)
    {
        cout << sep;
        sep = "\n";
        int N, E;
        cin >> N >> E;
        for (int i = 0; i < N; ++i)
            edges[i].clear();
        
        while (E--)
        {
            int i,j;
            cin >> i >> j;
            edges[i].push_back(j);
            edges[j].push_back(i);
        }
        
        BreadthPush(N);
        for (int i = 1; i < N; ++i)
            cout << number[i] << '\n';
    }
}