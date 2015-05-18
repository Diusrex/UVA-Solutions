#include <iostream>
#include <vector>

using namespace std;

double xPos[105];
double yPos[105];
double radius[105];

vector<int> intersectionGroups[105];
vector<int> *intersectionGroupBelongingTo[105];

double Square(double num)
{
    return num * num;
}

bool Intersect(int first, int second)
{
    double diff = Square(xPos[first] - xPos[second]) + Square(yPos[first] - yPos[second]);
    
    return (Square(radius[first] - radius[second]) <= diff
            && diff <= Square(radius[first] + radius[second]));
}

void JoinGroups(vector<int> *firstGroup, vector<int> *secondGroup)
{
    if (firstGroup != secondGroup)
    {
        for (int i = 0; i < secondGroup->size(); ++i)
        {
            int pos = (*secondGroup)[i];
            intersectionGroupBelongingTo[pos] = firstGroup;
            
            firstGroup->push_back(pos);
        }
    }
}

int main()
{
    int N;
    while (cin >> N, N != -1)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> xPos[i] >> yPos[i] >> radius[i];
            
            // Set up some additional state
            intersectionGroups[i].clear();
            intersectionGroups[i].push_back(i);
            intersectionGroupBelongingTo[i] = &intersectionGroups[i];
            
            for (int j = 0; j < i; ++j)
            {
                if (Intersect(i, j))
                {
                    JoinGroups(intersectionGroupBelongingTo[j],
                        intersectionGroupBelongingTo[i]);
                }
            }
        }
        
        int largestGroupSize = 0;
        
        for (int i = 0; i < N; ++i)
            largestGroupSize = max(largestGroupSize, (int) intersectionGroups[i].size());
        
        if (largestGroupSize != 1)
            cout << "The largest component contains " << largestGroupSize << " rings.\n";
        else
            cout << "The largest component contains " << largestGroupSize << " ring.\n";
    }
}