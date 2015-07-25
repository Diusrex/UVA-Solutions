#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Distance
{
    int key1, key2, dist;
    
    bool operator<(const Distance &other) const
    {
        return dist < other.dist;
    }
};


vector<string> numbers;
vector<Distance> distances;
vector<bool> reached;

int Dist(const string& first, const string& second)
{
    int dist = 0;
    for (int c = 0; c < 4; ++c)
    {
        int lowest = min(first[c], second[c]);
        int highest = max(first[c], second[c]);
        
        dist += min(highest - lowest, lowest + 10 - highest);
    }
    
    return dist;
}

bool CanAddFrom(const int from, const int toAdd)
{
    return reached[from] && !reached[toAdd];
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int N;
        cin >> N;
        
        numbers.resize(N);
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        // Find the closest to base
        int closestDist = 1000000;
        int closest;
        for (int i = 0; i < N; ++i)
        {
            int tempDist = Dist(numbers[i], "0000");
            if (tempDist < closestDist)
            {
                closestDist = tempDist;
                closest = i;
            }
        }
        
        int totalCost = closestDist;
        reached.assign(N, false);
        reached[closest] = true;
        
        int numDistances = N * (N - 1) / 2;
        distances.resize(numDistances);
        int index = 0;
        
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j, ++index)
            {
                distances[index].key1 = i;
                distances[index].key2 = j;
                distances[index].dist = Dist(numbers[i], numbers[j]);
            }
        }
        
        sort(distances.begin(), distances.begin() + numDistances);
        
        for (int numAdded = 1; numAdded < N; ++numAdded)
        {
            for (int dist = 0; ; ++dist)
            {
                if (CanAddFrom(distances[dist].key1, distances[dist].key2))
                {
                    reached[distances[dist].key2] = true;
                    totalCost += distances[dist].dist;
                    break;
                }
                
                if (CanAddFrom(distances[dist].key2, distances[dist].key1))
                {
                    reached[distances[dist].key1] = true;
                    totalCost += distances[dist].dist;
                    break;
                }
            }
        }
        
        cout << totalCost << '\n';
    }
}



