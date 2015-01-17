#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        bool stackPossible = true, queuePossible = true, priorityPossible = true;
        stack<int> usedStack;
        queue<int> usedQueue;
        priority_queue<int> usedPriority;
        
        while (n--)
        {
            int first, second;
            cin >> first >> second;
            
            switch (first)
            {
            case 1:
                if (stackPossible)
                    usedStack.push(second);
                if (queuePossible)
                    usedQueue.push(second);
                if (priorityPossible)
                    usedPriority.push(second);
                break;
                
            case 2:
                if (stackPossible)
                {
                    if (usedStack.empty() || usedStack.top() != second)
                        stackPossible = false;
                    else
                        usedStack.pop();
                }
                if (queuePossible)
                {
                    if (usedQueue.empty() || usedQueue.front() != second)
                        queuePossible = false;
                    else
                        usedQueue.pop();
                }
                if (priorityPossible)
                {
                    if (usedPriority.empty() || usedPriority.top() != second)
                        priorityPossible = false;
                    else
                        usedPriority.pop();
                }
                break;
            }
        }
        
        if (!stackPossible && !queuePossible && !priorityPossible)
            cout << "impossible\n";
        else if ((stackPossible && queuePossible) ||
                (stackPossible && priorityPossible) ||
                (queuePossible && priorityPossible))
            cout << "not sure\n";
        else if (stackPossible)
            cout << "stack\n";
        else if (queuePossible)
            cout << "queue\n";
        else
            cout << "priority queue\n";
    }
}