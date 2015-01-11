#include <iostream>
#include <vector>

// Is also possible to complete in O(n^3) time too
using namespace std;

string separator;

struct Node
{
    Node()
        : completed(false)
    {}
    
    void PrintOut()
    {
        if (completed)
            return;
        
        for (int i = 0; i < requiredNodes.size(); ++i)
            requiredNodes[i]->PrintOut();
        
        cout << separator << value;
        completed = true;
        separator = " ";
    }

    int value;
    bool completed;
    vector<Node*> requiredNodes;
};


int main()
{
    int n, m;
    while (cin >> n >> m, n)
    {
        ++n;
        vector<Node> nodes(n);
        for (int i = 1; i < n; ++i)
            nodes[i].value = i;
        
        for (int i = 0; i < m; ++i)
        {
            int first, second;
            cin >> first >> second;
            nodes[second].requiredNodes.push_back(&(nodes[first]));
        }
        
        separator = "";
        
        for (int i = 1; i < n; ++i)
            nodes[i].PrintOut();
            
        cout << '\n';
    }
}