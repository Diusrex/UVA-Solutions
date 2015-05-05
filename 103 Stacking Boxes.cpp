#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Box
{
    Box(int numDimen)
        : dimens(numDimen)
    {}
        
    int origionalPos;
    
    vector<int> dimens;
};

const int UNKNOWN = -1;

int dimen, N;
int numberFit[35];
int bestToHaveInside[35];

bool MyIntComp(int i, int j)
{
    return i > j;
}

bool MyComparison(const Box &l, const Box &r) 
{
    for (int i = 0; i < dimen; ++i)
        if (l.dimens[i] != r.dimens[i])
            return l.dimens[i] > r.dimens[i];
    
    return l.origionalPos < r.origionalPos;
}


bool CanFit(const Box &smaller, const Box &larger)
{
    for (int i = 0; i < dimen; ++i)
        if (smaller.dimens[i] >= larger.dimens[i])
            return false;
    
    return true;
}

int NumberCanFit(int pos, const vector<Box> &allBoxes)
{
    int &most = numberFit[pos];
    
    if (most == UNKNOWN)
    {
        most = 0;
        bestToHaveInside[pos] = -1;
        
        const Box &current = allBoxes[pos];
        
        for (int i = pos + 1; i < N; ++i)
        {
            if (CanFit(allBoxes[i], current))
            {
                int newVal = NumberCanFit(i, allBoxes);
                if (newVal > most)
                {
                    most = newVal;
                    bestToHaveInside[pos] = i;
                }
            }
        }
        
        ++most;
    }
    
    return most;
}

int main()
{
    vector<Box> allBoxes;
    while (cin >> N >> dimen)
    {
        allBoxes.assign(N, Box(dimen));
        
        for (int i = 0; i < N; ++i)
        {
            numberFit[i] = UNKNOWN;
        
            allBoxes[i].origionalPos = i + 1;
            
            for (int j = 0; j < dimen; ++j)
                cin >> allBoxes[i].dimens[j];
            sort(allBoxes[i].dimens.begin(), allBoxes[i].dimens.end(), MyIntComp);
        }
        
        sort(allBoxes.begin(), allBoxes.end(), MyComparison);
        
        int largestScore = NumberCanFit(0, allBoxes);
        int bestToStart = 0;
        
        for (int i = 1; i < N; ++i)
        {
            int tempScore = NumberCanFit(i, allBoxes);
            if (tempScore > largestScore)
            {
                largestScore = tempScore;
                bestToStart = i;
            }
        }
        
        cout << largestScore << '\n';

        stack<int> reverseOrder;
        int current = bestToStart;
        
        while (current != -1)
        {
            reverseOrder.push(allBoxes[current].origionalPos);
            current = bestToHaveInside[current];
        }
        
        current = reverseOrder.top();
        reverseOrder.pop();
        while (!reverseOrder.empty())
        {
            cout << current << ' ';
            current = reverseOrder.top();
            reverseOrder.pop();
        }
        
        cout << current << '\n';
    }
}