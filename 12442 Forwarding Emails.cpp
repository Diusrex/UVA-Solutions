#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


const int NOT_CHECKED = -1;

void solve(int N, const vector<int>& whoTo, vector<int>& sendMax)
{
    for (int i = 0; i < N; ++i)
    {
        if (sendMax[i] == NOT_CHECKED)
        {
            vector<int> orderOfTraversal;
            vector<bool> reached(N, false);
            
            int current = i;
            
            while (sendMax[current] == NOT_CHECKED && !reached[current])
            {
                reached[current] = true;
                orderOfTraversal.push_back(current);
                current = whoTo[current];
            }
            
            // Reached an already know spot
            if (sendMax[current] != NOT_CHECKED)
            {
                int size = orderOfTraversal.size();
                for (int pos = size - 1; pos >= 0; --pos)
                {
                    sendMax[orderOfTraversal[pos]] = sendMax[current] + (size - pos);
                }
            }
            
            // Created a cycle
            else
            {
                int currentPosInOrder;
                
                for (currentPosInOrder = 0; orderOfTraversal[currentPosInOrder] != current; ++currentPosInOrder);
                
                int sizeOfCycle = orderOfTraversal.size() - currentPosInOrder;
                
                for (int pos = currentPosInOrder; pos < orderOfTraversal.size(); ++pos)
                {
                    sendMax[orderOfTraversal[pos]] = sizeOfCycle;
                }
                
                for (int pos = 0; pos < currentPosInOrder; ++pos)
                {
                    sendMax[orderOfTraversal[pos]] = sizeOfCycle + (currentPosInOrder - pos);
                }
            }
        }
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; ++t)
    {
        int N;
        scanf("%d", &N);
        
        vector<int> whoTo(N);
        
        for (int i = 0; i < N; ++i)
        {
            int posFrom, value;
            scanf("%d %d", &posFrom, &value);
            whoTo[posFrom - 1] = value - 1;
        }
    
        vector<int> sendMax(N, NOT_CHECKED);
        
        solve(N, whoTo, sendMax);
        
        int bestPos = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if (sendMax[i] > sendMax[bestPos])
                bestPos = i;
        }
        
        printf("Case %d: %d\n", t, bestPos + 1);
    }
}