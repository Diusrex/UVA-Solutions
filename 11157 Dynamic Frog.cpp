#include <iostream>

using namespace std;

int N;
bool isSmall[105];
bool hit[105];
// positions[N] = D
int positions[105];

// Will always need to skip over the small rocks at least once
int GetWorstDistance()
{
    int minDist = positions[0];
    for (int i = 0; i < N; ++i)
    {
        hit[i] = true;
        // Skip over first small for now
        if (!isSmall[i + 1])
        {
            minDist = max(minDist, positions[i + 1] - positions[i]);
        }
        else
        {
            minDist = max(minDist, positions[i + 2] - positions[i]);
            ++i;
        }
    }
    
    for (int i = N; i > 0; --i)
    {
        if (!hit[i - 1] || !isSmall[i - 1])
        {
            minDist = max(minDist, positions[i] - positions[i - 1]);
        }
        else
        {
            minDist = max(minDist, positions[i] - positions[i - 2]);
            --i;
        }
    }
    return minDist;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        int D;
        cin >> N >> D;
        for (int i = 0; i < N; ++i)
        {
            char type, sep;
            cin >> type >> sep >> positions[i];
            isSmall[i] = (type == 'S');
            
            hit[i] = false;
        }
        
        isSmall[N] = false;
        positions[N] = D;
        hit[N] = false;
        
        cout << "Case " << t << ": " <<
            GetWorstDistance() << '\n';
    }
}