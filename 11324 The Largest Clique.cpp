#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nodeEdges[1005];

const int Unknown = -1;

int numEncountered;
int encounteredNum[1005];
int lowestEncountered[1005];
stack<int> nodesOrder;

int numComponents;
int component[1005];
int componentSize[1005];
int largestCount[1005];
vector<int> componentEdges[1005];
bool counted[1005];

void SCCFind(int node)
{
    lowestEncountered[node] = encounteredNum[node] = numEncountered++;
    
    nodesOrder.push(node);
    
    for (int e = 0; e < nodeEdges[node].size(); ++e)
    {
        int check = nodeEdges[node][e];
        if (encounteredNum[check] == Unknown)
            SCCFind(check);
        
        lowestEncountered[node] = min(lowestEncountered[node], lowestEncountered[check]);
    }
    
    // is `Root` of SCC
    if (lowestEncountered[node] == encounteredNum[node])
    {
        componentSize[numComponents] = 0;
        
        int current = -1;
        while (current != node)
        {
            current = nodesOrder.top();
            nodesOrder.pop();
            lowestEncountered[current] = 10000;
            component[current] = numComponents;
            ++componentSize[numComponents];
        }
        
        ++numComponents;
    }
}

int GetCount(int component)
{
    if (largestCount[component] == Unknown)
    {
        largestCount[component] = 0;
        for (int e = 0; e < componentEdges[component].size(); ++e)
        {
            int to = componentEdges[component][e];
            if (to != component && !counted[to])
            {
                largestCount[component] = max(largestCount[component], GetCount(to));
            }
        }
        largestCount[component] += componentSize[component];
    }
    return largestCount[component];
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < n; ++i)
        {
            nodeEdges[i].clear();
            componentEdges[i].clear();
            encounteredNum[i] = Unknown;
        }
        
        while (m--)
        {
            int start, end;
            cin >> start >> end;
            nodeEdges[start - 1].push_back(end - 1);
        }
        
        numEncountered = numComponents = 0;
        // Create SCC first
        for (int i = 0; i < n; ++i)
        {
            if (encounteredNum[i] == Unknown)
                SCCFind(i);
        }
        // Create their edges. Will have duplicates, and edges to itself
        // Note it goes to is transformed.
        for (int i = 0; i < n; ++i)
        {
            for (int e = 0; e < nodeEdges[i].size(); ++e)
            {
                componentEdges[component[i]].push_back(component[nodeEdges[i][e]]);
            }
        }
        
        for (int i = 0; i < numComponents; ++i)
            largestCount[i] = Unknown;
        
        int largest = 0;
        for (int i = 0; i < numComponents; ++i)
        {
            largest = max(largest, GetCount(i));
        }
        
        cout << largest << '\n';
    }
}
