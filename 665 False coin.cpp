#include <cstdio>
#include <set>

using namespace std;

void ReadSide(const int& numPerSide, set<int>& numbers)
{
    numbers.clear();
    for (int coin = 0; coin < numPerSide; ++coin)
    {
        int num;
        scanf("%d", &num);
        numbers.insert(num);
    }
}

void RemoveFrom(set<int>& setRemovedFrom, const set<int>& removedValues)
{
    for (set<int>::const_iterator iter = removedValues.begin(); iter != removedValues.end(); ++iter)
    {
        setRemovedFrom.erase(*iter);
    }
}

set<int> Union(const set<int>& left, const set<int>& right)
{
    set<int> setsUnion;
    for (set<int>::const_iterator iter = left.begin(); iter != left.end(); ++iter)
    {
        if (right.find(*iter) != right.end())
            setsUnion.insert(*iter);
    }
    
    return setsUnion;
}

set<int> Combine(const set<int>& left, const set<int>& right)
{
    set<int> combined;
    
    for (set<int>::const_iterator iter = left.begin(); iter != left.end(); ++iter)
        combined.insert(*iter);
    
    for (set<int>::const_iterator iter = right.begin(); iter != right.end(); ++iter)
        combined.insert(*iter);
        
    return combined;
}

void InterpretResult(const char &result, const set<int>& left, const set<int>&right, set<int>& lessThan, set<int>& greater)
{
    if (result == '=')
    {
        RemoveFrom(lessThan, left);
        RemoveFrom(lessThan, right);
        
        RemoveFrom(greater, left);
        RemoveFrom(greater, right);
    }
    else if (result == '<')
    {
        lessThan = Union(lessThan, right);
        RemoveFrom(lessThan, left);
        greater = Union(greater, left);
        RemoveFrom(greater, right);
    }
    else
    {
        lessThan = Union(lessThan, left);
        RemoveFrom(lessThan, right);
        greater = Union(greater, right);
        RemoveFrom(greater, left);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    bool first = true;
    
    while (T--)
    {
        if (!first)
            printf("\n");
        first = false;
        
        int numCoins, numWeighing;
        scanf("%d%d", &numCoins, &numWeighing);
        
        // Will ignore the 0th coin
        set<int> lessThan, combined;
        for (int i = 1; i <= numCoins; ++i)
            lessThan.insert(i);
        
        set<int> greater = lessThan;
        
        int numPerSide;
        set<int> left, right;
        
        int wrongCoin = 0;
        
        for (int i = 0; i < numWeighing; ++i)
        {
            scanf("%d", &numPerSide);
            
            ReadSide(numPerSide, left);
            ReadSide(numPerSide, right);
            
            char result;
            scanf(" %c ", &result);
            
            if (wrongCoin == 0)
            {
                InterpretResult(result, left, right, lessThan, greater);
                
                combined = Combine(lessThan, greater);
                
                if (combined.size() == 1)
                {
                    if (lessThan.size() == 1)
                        wrongCoin = *lessThan.begin();
                    else
                        wrongCoin = *greater.begin();
                }
            }
        }
        
        printf("%d\n", wrongCoin);
    }
}