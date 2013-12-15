#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    Node(): nextNode(-1), previousNode(-1), atOrigional(true) {}
    bool atOrigional;
    int nextNode, previousNode;
};

void PrintOut(const vector<Node>& allNodes, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << i << ":";
        
        if (allNodes[i].atOrigional)
        {
            int x = i;
            
            while (x != -1)
            {
                cout << " " << x;
                x = allNodes[x].nextNode;            
            }
        
        }
        cout << '\n';
    }

}

int main()
{
    int n;
    cin >> n;
    
    vector<Node> allNodes(n);
    
    
    string mainCommand, secondaryCommand;
    cin >> mainCommand;
    
    while (mainCommand != "quit")
    {
        int a, b;
        cin >> a >> secondaryCommand >> b;
        
        bool valid(true);
        
        if (a == b)
            valid = false;
            
        int c = a;
        
        while (c != -1 && c != b)
            c = allNodes[c].nextNode;
        
        if (c == b)
            valid = false;
        
        if (!valid)
        {
            cin >> mainCommand;
            continue;
        }
        
        c = b;
        
        while (c != -1 && c != a)
            c = allNodes[c].nextNode;
            
        if (c == a)
        {
            cin >> mainCommand;
            continue;
        }
        
        if (secondaryCommand == "onto")
        {
            int current = allNodes[b].nextNode;
                
            while (current != -1)
            {
                allNodes[current].atOrigional = true;
                allNodes[current].previousNode = -1;
                int temp = current;
                current = allNodes[current].nextNode;
                allNodes[temp].nextNode = -1;            
            }
        }
        
        else
        {
            while (allNodes[b].nextNode != -1)
                b = allNodes[b].nextNode;            
        }
        
        
        if (mainCommand == "move")
        {
            int current = allNodes[a].nextNode;
                
            while (current != -1)
            {
                allNodes[current].previousNode = -1;    
                allNodes[current].atOrigional = true;
                int temp = current;
                current = allNodes[current].nextNode;
                allNodes[temp].nextNode = -1;            
            }
            
            allNodes[a].nextNode = -1;
        }
        
        // Moves a off of previous
        if (allNodes[a].previousNode != -1)
            allNodes[allNodes[a].previousNode].nextNode = -1;
        
        // Puts a onto b, or b's child
        allNodes[b].nextNode = a;
        allNodes[a].previousNode = b;
        
        allNodes[a].atOrigional = false;
        
        //PrintOut(allNodes, n);
        
        cin >> mainCommand;   
    }
    PrintOut(allNodes, n);
    
    

}