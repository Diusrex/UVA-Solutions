#include <string>
#include <iostream>
#include <set>

// Using a set is probably overkill for this problem, but most of the code was just copied from my solution to #665

using namespace std;

const int NUM_COINS = 12;
const int NUM_WEIGHINGS = 3;

void ReadSide(set<int>& numbers)
{
    numbers.clear();
    string allCoins;
    cin >> allCoins;
    for (string::const_iterator iter = allCoins.begin(); iter != allCoins.end(); ++iter)
        numbers.insert(*iter - 'A');
}

void RemoveFrom(set<int>& setRemovedFrom, const set<int>& removedValues)
{
    for (set<int>::const_iterator iter = removedValues.begin(); iter != removedValues.end(); ++iter)
        setRemovedFrom.erase(*iter);
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

void InterpretResult(const string &result, const set<int>& left, const set<int>&right, set<int>& lessThan, set<int>& greater)
{
    switch (result[0])
    {
    case 'e':
        RemoveFrom(lessThan, left);
        RemoveFrom(lessThan, right);
        
        RemoveFrom(greater, left);
        RemoveFrom(greater, right);
        break;
        
    case 'u':
        lessThan = Union(lessThan, right);
        RemoveFrom(lessThan, left);
        greater = Union(greater, left);
        RemoveFrom(greater, right);
        break;
    
    case 'd':
        lessThan = Union(lessThan, left);
        RemoveFrom(lessThan, right);
        greater = Union(greater, right);
        RemoveFrom(greater, left);
        break;
    }
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        set<int> lessThan, combined;
        for (int i = 0; i <= NUM_COINS; ++i)
            lessThan.insert(i);
        
        set<int> greater = lessThan;
        
        set<int> left, right;
        
        int wrongCoin = -1;
        
        for (int i = 0; i < NUM_WEIGHINGS; ++i)
        {
            ReadSide(left);
            ReadSide(right);
            
            string result;
            cin >> result;
            
            if (wrongCoin == -1)
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
        
        char coin = 'A' + wrongCoin;
        
        if (lessThan.size() == 1)
            cout << coin << " is the counterfeit coin and it is light.\n";
        else
            cout << coin << " is the counterfeit coin and it is heavy.\n";
    }
}