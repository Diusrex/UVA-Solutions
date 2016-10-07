/* Data Structures: Lazy Segment Tree
   =================================================================
   Description: Segment Tree Structure
   
   Complexity:  Let N be the size of the heap:
                Insertion: O(lg N)
		Removal:   O(lg N)
   -----------------------------------------------------------------
   Author:      Morgan Redshaw
   Date:        October, 2016
   References:  Learned segment tree from Competitive Programming 3 awhile ago?
   -----------------------------------------------------------------
   Reliability: 2
   Notes:       - Current example is containing the value for each node,
                  with the update being a sum change to the value, and query
                  asking for the sum over the range
                - By following the TODOs, can be heavily customized to fit the
                  needs of the current problem.
*/

#include <iostream>

#include <string>
#include <vector>
#include <cmath>

// Note that I don't need a lazy segment tree for this problem, but eh

using namespace std;

const int MAX_N = 1024000;

struct Node
{
    int value;
    // Action will need to be applied to all children
    // Will already have been applied to the node
    // EG: Increase for all numbers in range
    int action;
    bool hasAction;
};

const int POSITIVE = 1;
const int ZERO = 0;
const int NEGATIVE = -1;

int N;
Node allNodes[5 * MAX_N];   

// After generating the segment tree, doesn't use the index specific array
int baseValue[MAX_N];

int GetValueFromChildren(int index)
{
    return allNodes[index * 2].value * allNodes[index * 2 + 1].value;
}

// Inclusive on both
void GenerateSegmentTree(int index, int nodeLeft, int nodeRight)
{
    allNodes[index].hasAction = false;
    
    if (nodeLeft == nodeRight)
    {
        allNodes[index].value = baseValue[nodeLeft];
        if (allNodes[index].value != 0)
            allNodes[index].value /= abs(allNodes[index].value);
        return;
    }
    
    int mid = (nodeLeft + nodeRight) / 2;
    
    GenerateSegmentTree(index * 2, nodeLeft, mid);
    GenerateSegmentTree(index * 2 + 1, mid + 1, nodeRight);
    
    allNodes[index].value = GetValueFromChildren(index);
}

void AddLazyUpdateAction(int index, int action)
{
    allNodes[index].action = action;
    allNodes[index].hasAction = true;
}

void ApplyAndPushLazyUpdate(int index, int nodeStart, int nodeEnd)
{
    if (!allNodes[index].hasAction)
        return;

    allNodes[index].value = allNodes[index].action;
    
    if (nodeStart != nodeEnd)
    {
        int middle = (nodeStart + nodeEnd) / 2;
        
        // Tell children about their lazy status
        AddLazyUpdateAction(index * 2, allNodes[index].action);
        AddLazyUpdateAction(index * 2 + 1, allNodes[index].action);
    }
    
    allNodes[index].hasAction = false;
}

// Inclusive on both starts and ends
void ApplyLazyChange(int index, int nodeStart, int nodeEnd, int changeStart, int changeEnd, int action)
{
    // Make sure the value is updated and moved to children
    ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
    
    if (nodeEnd < changeStart || nodeStart > changeEnd)
    {
        return;
    }
    
    // This index is contained completely
    if (nodeStart >= changeStart && nodeEnd <= changeEnd)
    {
        // Add the update to this node, then apply it so parent will get correct value.
        AddLazyUpdateAction(index, action);
        ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
        return;
    }
    
    int middle = (nodeStart + nodeEnd) / 2;
    
    ApplyLazyChange(index * 2, nodeStart, middle, changeStart, changeEnd, action);
    ApplyLazyChange(index * 2 + 1, middle + 1, nodeEnd, changeStart, changeEnd, action);
    
    allNodes[index].value = GetValueFromChildren(index);
}

// Inclusive on both starts and ends
int Query(int index, int nodeStart, int nodeEnd, int queryStart, int queryEnd)
{
    if (nodeEnd < queryStart || nodeStart > queryEnd)
        return POSITIVE;
    
    // Make sure the value is updated and moved to children
    ApplyAndPushLazyUpdate(index, nodeStart, nodeEnd);
    
    // This index is contained completely
    if (nodeStart >= queryStart && nodeEnd <= queryEnd)
    {
        return allNodes[index].value;
    }
    
    int middle = (nodeStart + nodeEnd) / 2;
    
    int count = Query(index * 2, nodeStart, middle, queryStart, queryEnd) *
                Query(index * 2 + 1, middle + 1, nodeEnd, queryStart, queryEnd);
    return count;
}

int main()
{
    int N, Q;
    
    while (cin >> N >> Q)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> baseValue[i];
        }
        
        GenerateSegmentTree(1, 0, N - 1);
        while (Q--)
        {
            string cmd;
            int i, j;
            
            cin >> cmd >> i >> j;
            --i;
            if (cmd == "P")
            {
                --j;
                int ans = Query(1, 0, N - 1, i, j);
                if (ans > 0)
                    cout << "+";
                else if (ans == 0)
                    cout << "0";
                else
                    cout << "-";
            }
            else
            {
                if (j != 0)
                    j /= abs(j);
                ApplyLazyChange(1, 0, N - 1, i, i, j);
            }
            
        }
        cout << "\n";
    }
}
