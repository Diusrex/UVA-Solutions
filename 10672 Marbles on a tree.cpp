#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
    int numMarbles;
    int marbleDiff;
    
    vector<node*> descendents;
    
    bool hasParent;
};

int Solve(node* current)
{
    if (current->descendents.size() == 0)
    {
        current->marbleDiff = current->numMarbles - 1;
        
        return abs(current->marbleDiff);
    }
    
    int count = 0;

    
    for (int i = 0; i < current->descendents.size(); ++i)
    {
        count += Solve(current->descendents[i]);
        current->marbleDiff += current->descendents[i]->marbleDiff;
    }
    
    current->marbleDiff += current->numMarbles - 1;
    count += abs(current->marbleDiff);
    
    return count;
}

int main()
{
    int n;
    
    while (scanf("%d", &n), n)
    {
        vector<node> verticies(n);
        
        for (int i = 0; i < n; ++i)
        {
            int num, numMarbles, descendents;
            scanf("%d%d%d", &num, &numMarbles, &descendents);
            --num;
            
            verticies[num].numMarbles = numMarbles;
            
            for (int d = 0; d < descendents; ++d)
            {
                int dPos;
                scanf("%d", &dPos);
                --dPos;
                verticies[num].descendents.push_back(&verticies[dPos]);
                verticies[dPos].hasParent = true;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (!verticies[i].hasParent)
            {
                printf("%d\n", Solve(&verticies[i]));
                break;
            }
        }
        
    }
}
