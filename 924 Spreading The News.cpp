#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int E;
    cin >> E;
    vector<vector<int> > neighbors(E);

    for (int i = 0; i < E; ++i)
    {
        int size;
        cin >> size;
        neighbors[i].resize(size);
        for (int j = 0; j < size; ++j)
            cin >> neighbors[i][j];
    }
    
    int T;
    cin >> T;
    
    vector<int> current(E); int numCurr = 0;
    vector<int> next(E); int numNext;
    vector<bool> hit(E);
    
    while (T--)
    {
        for (int i = 0; i < E; ++i)
            hit[i] = false;
        
        int start;
        cin >> start;
        int day = 1, bestDay = 0, highest = 0;
        hit[start] = true;
        current[numCurr++] = start;
        
        while (numCurr)
        {
            numNext = 0;
            for (int i = 0; i < numCurr; ++i)
            {
                for (vector<int>::iterator iter = neighbors[current[i]].begin();
                    iter != neighbors[current[i]].end(); ++iter)
                {
                    if (!hit[*iter])
                    {
                        hit[*iter] = true;
                        next[numNext++] = *iter;
                    }
                }
            }
            
            if (numNext > highest)
            {
                bestDay = day;
                highest = numNext;
            }
            
            numCurr = numNext;
            ++day;
            current.swap(next);
        }
        
        if (highest)
            cout << highest << ' ' << bestDay << '\n';
        else
            cout << "0\n";
        
    }
}