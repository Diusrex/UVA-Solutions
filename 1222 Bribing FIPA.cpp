#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

// Know:
    // It fails with too many numSorted
    // But there are none with double parents
    // And all are properly loaded in with different names
    // So what could be wrong?

int N;

// These are for the sortedIndex
int topologicallySorted[205], nextUndominatedCountry[205];

// Based on original order
int cost[205], numberWouldBuy[205];

// [current][countriesLeft]
int minimumCost[205][205];

int GetMinimumCost(int sortedIndex, int countriesNeeded)
{
    if (countriesNeeded <= 0)
        return 0;
    else if (N - sortedIndex < countriesNeeded)
        return -1;
    
    int &bestCost = minimumCost[sortedIndex][countriesNeeded];
    
    if (bestCost == -1)
    {
        int actualCountry = topologicallySorted[sortedIndex];
        
        // Cost for if it would be boughtout
        bestCost = GetMinimumCost(nextUndominatedCountry[sortedIndex], countriesNeeded - numberWouldBuy[actualCountry])
                    + cost[actualCountry];
        
        int ignoredCost = GetMinimumCost(sortedIndex + 1, countriesNeeded);
        if (ignoredCost != -1)
            bestCost = min(bestCost, ignoredCost);
    }
    return bestCost;
}

map<string, int> nameToIndex;

int GetIndex(const string & s)
{
    if (nameToIndex.find(s) == nameToIndex.end())
    {
        nameToIndex.insert(make_pair(s, nameToIndex.size()));
    }
    
    return nameToIndex[s];
}


// For creating the topological sort, in order of input
bool hasParent[205];
vector<int> children[205];


void ParseLine(const string &line)
{
    stringstream ss(line);
    
    string country;
    ss >> country;
    
    int baseIndex = GetIndex(country);
    ss >> cost[baseIndex];
    
    while (ss >> country)
    {
        int dominatedIndex = GetIndex(country);
        hasParent[dominatedIndex] = true;
        children[baseIndex].push_back(dominatedIndex);
    }
}

int numSorted;
// Assume already handled parents
// Returns number of nodes this node dominates
int ConstructTopologicalTopDown(int node)
{
    // Makes it easier to keep access to
    int &nextUndominated = nextUndominatedCountry[numSorted];
    
    // Needs to have numberWouldBuy added
    nextUndominated = numSorted;
    numberWouldBuy[node] = 1;
    
    topologicallySorted[numSorted++] = node;
    

    for (int i = 0; i < children[node].size(); ++i)
    {
        numberWouldBuy[node] += ConstructTopologicalTopDown(children[node][i]);
    }
    
    nextUndominated += numberWouldBuy[node];
    return numberWouldBuy[node];
}


int main()
{
    while (cin.peek() != '#')
    {
        int m;
        cin >> N >> m;
        
        nameToIndex.clear();
        for (int i = 0; i < N; ++i)
        {
            hasParent[i] = false;
            for (int j = 0; j <= m; ++j)
                minimumCost[i][j] = -1;
            
            children[i].clear();
        }
        
        numSorted = 0;
        
        cin.ignore();
        for(int i = 0; i < N; ++i)
        {
            string line;
            getline(cin, line);
            ParseLine(line);
        }
        
        for (int i = 0; i < N; ++i)
        {
            if (!hasParent[i])
                ConstructTopologicalTopDown(i);
        }
        
        int bestCost = GetMinimumCost(0, m);
        cout << bestCost << '\n';
    }
}