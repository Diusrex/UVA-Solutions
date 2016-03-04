#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const int Impossible = -1;
const int MaxNumPlanets = 251;
int numHuman, numAlien;

int initialHuman[MaxNumPlanets], initialAlien[MaxNumPlanets];
int humanGrowth[MaxNumPlanets], alienGrowth[MaxNumPlanets];

int timeToDefeat[MaxNumPlanets][MaxNumPlanets];

int YearsToDefeat(int human, int alien, int timeToTravel)
{
    // Send immediately, since will just be wasting time otherwise
    if (humanGrowth[human] <= alienGrowth[alien])
    {
        if (initialHuman[human] >= initialAlien[alien] + timeToTravel * alienGrowth[alien])
            return timeToTravel;
        
        return Impossible;
    }
    
    int additionalNeeded = initialAlien[alien] - initialHuman[human]  + timeToTravel * alienGrowth[alien];
    int increasePerYear = humanGrowth[human] - alienGrowth[alien];
    int baseYears = additionalNeeded / increasePerYear;
    
    return timeToTravel + baseYears + ((additionalNeeded % increasePerYear != 0) ? 1 : 0);
}

const int MaxNumNodes = 500;
bool edge[MaxNumNodes][MaxNumNodes];
int match[MaxNumNodes];

void addEdge(int uIndex, int vIndex, int sizeOfU)
{
    edge[uIndex][vIndex + sizeOfU] = edge[vIndex + sizeOfU][uIndex] = true;
}

int find(int node, int totalNumberNodes)
{
    if (match[node] != -1)
        return 0;
    
    int nodesInOrder[MaxNumNodes];
    
    // Back stores the reverse order of accessess
    int back[MaxNumNodes];

    for (int i = 0; i < totalNumberNodes; ++i)
        back[i] = -1;

    nodesInOrder[0] = node;
    for (int i = 0, numNodesEncountered = 1; i < numNodesEncountered; i++)
    {
        const int currentNode = nodesInOrder[i];
        for (int j = 0; j < totalNumberNodes; j++)
        {
            // Ensure is edge from currentNode to j
            if (!edge[currentNode][j])
                continue;

            // j has already been encountered as a match
            if (match[j] != -1)
            {
                // Ensure we havent reached it already in this iteration
                if (back[j] == -1)
                {
                    back[j] = currentNode;
                    nodesInOrder[numNodesEncountered] = match[j];
                    back[match[j]] = j;
                    numNodesEncountered++;
                }
            } 
            else
            {
                match[currentNode] = j;
                match[j] = currentNode;
                for (int r = back[currentNode]; r != -1; r = back[back[r]])
                {
                    match[r] = back[r];
                    match[match[r]] = r;
                }

                return 1;
            }
        }
    }
    return 0;
}

void bipmatch(int totalNumberNodes)
{
    // Reset the matches
    for (int i = 0; i < totalNumberNodes; ++i)
        match[i] = -1;
    
    for (int i = 0; i < totalNumberNodes; i++)
        find(i, totalNumberNodes);
}

bool CanBeCompletedInTime(int maxTimeAllowed)
{
    // This is from their main
    
    // Clear edges
    for (int i = 0; i < numHuman + numAlien; ++i)
        for (int j = 0; j < numHuman + numAlien; ++j)
            edge[i][j] = edge[j][i] = false;
    
    for (int human = 0; human < numHuman; ++human)
    {
        for (int alien = 0; alien < numAlien; ++alien)
            if (timeToDefeat[human][alien] <= maxTimeAllowed)
                addEdge(human, alien, numHuman);
    }

    bipmatch(numHuman + numAlien);

    int count = 0;
    for (int i = 0; i < numHuman; i++)
        if (match[i] != -1)
            count++;
    
    return count == numAlien;
}

// inclusive on both
int BinarySearch(int overallMin, int overallMax)
{
    int testedTime;
    
    while (testedTime = (overallMin + (overallMax - overallMin) / 2), testedTime != overallMin)
    {
        if (CanBeCompletedInTime(testedTime))
            overallMax = testedTime;
        
        else // Know this time will fail
            overallMin = testedTime + 1;
    }
    
    return testedTime;
}

int main()
{
    while (cin >> numHuman >> numAlien, numAlien)
    {
        // Read in input
        for (int i = 0; i < numHuman; ++i)
            cin >> initialHuman[i] >> humanGrowth[i];
        
        for (int i = 0; i < numAlien; ++i)
            cin >> initialAlien[i] >> alienGrowth[i];
        
        int overallMax = -1;
        int overallMin = std::numeric_limits<int>::max();
        for (int human = 0; human < numHuman; ++human)
        {
            for (int alien = 0; alien < numAlien; ++alien)
            {
                int travel;
                cin >> travel;
                
                timeToDefeat[human][alien] = YearsToDefeat(human, alien, travel);
                overallMax = max(overallMax, timeToDefeat[human][alien]);
                if (timeToDefeat[human][alien] != Impossible) // Means is possible
                    overallMin = min(overallMin, timeToDefeat[human][alien]);
                else
                   timeToDefeat[human][alien] = std::numeric_limits<int>::max();
            }
        }
        
        bool possible = false;
        
        // There are at least as many human worlds, and at least one human planet
        // can conquer an alien plane
        if (numHuman >= numAlien && overallMax != -1)
        {
            int value = BinarySearch(overallMin, overallMax);
            
            possible = CanBeCompletedInTime(value);
            if (possible)
                cout << value << '\n';
        }
        if (!possible)
            cout << "IMPOSSIBLE\n";
    }
}