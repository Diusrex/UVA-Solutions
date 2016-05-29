#include <iostream>
#include <set>

using namespace std;

// Probably dont need this
typedef unsigned long long ull;

set<int> possibleScores;

const int Highest = 181;
const int HighestScore = 65; // Slightly higher
ull combinations[Highest][HighestScore][4];
ull permutations[Highest][4];

// Must use num >= highestThrown
int GetComb(int scoreLeft, int highestThrown, int throwsLeft)
{
    if (scoreLeft == 0 && throwsLeft == 0)
        return 1;
    else if (scoreLeft <= 0 || throwsLeft == 0 || scoreLeft >= Highest)
        return 0;
    
    ull &combs = combinations[scoreLeft][highestThrown][throwsLeft];
    if (combs == -1)
    {
        combs = 0;
        for (set<int>::iterator score = possibleScores.lower_bound(highestThrown); score != possibleScores.end(); ++score)
        {
            combs += GetComb(scoreLeft - *score, *score, throwsLeft - 1);
        }
    }
    
    return combs;
}

int GetPerm(int scoreLeft, int throwsLeft)
{
    if (scoreLeft == 0)
        return 1;
    else if (scoreLeft < 0 || throwsLeft == 0 || scoreLeft >= Highest)
        return 0;
    
    ull &perms = permutations[scoreLeft][throwsLeft];
    if (perms == -1)
    {
        perms = 0;
        for (set<int>::iterator score = possibleScores.begin(); score != possibleScores.end(); ++score)
        {
            perms += GetPerm(scoreLeft - *score, throwsLeft - 1);
        }
    }
    
    return perms;
}

int main()
{
    int goal;
    for (int i = 0; i <= 20; ++i)
    {
        possibleScores.insert(i);
        possibleScores.insert(i * 2);
        possibleScores.insert(i * 3);
    }
    possibleScores.insert(50);
    
    for (int i = 0; i < Highest; ++i)
        for (int t = 0; t < 4; ++t)
            permutations[i][t] = -1;
    
    for (int i = 0; i < Highest; ++i)
        for (int s = 0; s < HighestScore; ++s)
            for (int t = 0; t < 4; ++t)
                combinations[i][s][t] = -1;
        
    
    while (cin >> goal, goal > 0)
    {
        int perms = GetPerm(goal, 3);
        if (perms == 0)
            cout << "THE SCORE OF " << goal << " CANNOT BE MADE WITH THREE DARTS.\n";
        else
        {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << goal << " IS " << GetComb(goal, 0, 3) << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << goal << " IS " << perms << ".\n";
        
        }
        cout << "**********************************************************************\n";
    }
    
    cout << "END OF OUTPUT\n";
}