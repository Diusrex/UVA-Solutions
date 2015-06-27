#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Best is find all nodes that don't depend on others
// Or, could do dependent on
    // And 
// Use a priority queue?
// Dependent on

#define MAX_NUM_VARIABLES 23

// THESE WILL BE SORTED
char characters[MAX_NUM_VARIABLES];
int characterToIndex[128];

// This is a bitmask, where a 1 means dependent on
int dependentOn[MAX_NUM_VARIABLES];

int N;
bool oneIsPossible;

inline bool NotPrinted(int toCheck, int printed)
{
    int toCheckMask = (1 << toCheck);
    return !(toCheckMask & printed);
}

// Will check to see if every one toCheck is dependent on has has been printed
inline bool ConditionMet(int toCheck, int printed)
{
    return (printed & dependentOn[toCheck]) == dependentOn[toCheck];
}

// MUST BE SORTED BEFORE THIS FUNCTION
void PrintOut(int numPrinted, int printed, vector<char> &toPrint)
{
    if (numPrinted == N)
    {
        cout << toPrint[0];
        
        for (int i = 1; i < N; ++i)
        {
            cout << ' ' << toPrint[i];
        }
        cout << '\n';
        oneIsPossible = true;
        return;
    }
    
    for (int i = 0; i < N; ++i)
    {
        if (NotPrinted(i, printed) && ConditionMet(i, printed))
        {
            toPrint[numPrinted] = characters[i];
            PrintOut(numPrinted + 1, printed | (1 << i), toPrint);
        }
        
    }
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    string line, sep = "";
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        cin.ignore();
        getline(cin, line);
        
        N = 0;
        
        for (int i = 0; i < line.size(); i += 2)
            characters[N++] = line[i];
        
        sort(characters, characters + N);
        for (int i = 0; i < N; ++i)
        {
            characterToIndex[characters[i]] = i;
            dependentOn[i] = 0;
        }
        getline(cin, line);
        for (int i = 0; i < line.size(); i += 4)
        {
            int first = characterToIndex[line[i]], second = characterToIndex[line[i + 2]];
            dependentOn[second] |= (1 << first);
        }
        
        vector<char> toPrint(N);
        
        oneIsPossible = false;
        
        PrintOut(0, 0, toPrint);
        
        if (!oneIsPossible)
            cout << "NO\n";
    }
}