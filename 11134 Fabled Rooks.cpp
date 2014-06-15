#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

bool SolveGroup(const std::vector<pair<int, int> >& group, vector<int>& answers, int n)
{
    std::vector<bool> chosen(n, false);
    
    // Each run. current value
    for (int currentLine = 1; currentLine <= n; ++currentLine)
    {
        int bestPos = -1;
        
        for (int current = 0; current < n; ++current)
        {
            if (!chosen[current] && group[current].first <= currentLine)
            {
                if (bestPos == -1 || group[current].second < group[bestPos].second)
                {
                    bestPos = current;
                }
            }
        }
        
        if (bestPos == -1 || group[bestPos].second < currentLine)
            return false;
            
        chosen[bestPos] = true;
        answers[bestPos] = currentLine;
    }

}



int main()
{
    int n;
    
    while (scanf("%d", &n), n != 0)
    {
        vector<pair<int, int> > rows(n);
        vector<pair<int, int> > columns(n);
        
        vector<int> rowAnswers(n), columnAnswers(n);
        
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d %d %d", &rows[i].first, &columns[i].first, &rows[i].second, &columns[i].second);
        }
        
        if (SolveGroup(rows, rowAnswers, n) && SolveGroup(columns, columnAnswers, n))
        {
            for (int i = 0; i < n; ++i)
            {
                printf("%d %d\n", rowAnswers[i], columnAnswers[i]);
            }
        }
        
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }

}