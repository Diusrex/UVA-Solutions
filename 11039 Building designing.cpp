#include <iostream>
#include <algorithm>

using namespace std;

// Will just be switching back and forth between Red and blue
// So can just try out starting with a red, vs starting with a blue
// and see which gets the highest

struct Floor
{
    int size;
    int color;
    
    bool operator<(const Floor & other)
    {
        return size > other.size;
    }
};

int N;
Floor floors[500005];

int StartWithColor(int color)
{
    int count = 0;
    
    int neededColor = 1 - color;
    for (int i = 0; i < N; ++i)
        if (floors[i].color == neededColor)
        {
            ++count;
            neededColor = 1 - neededColor;
        }
        
    return count;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> floors[i].size;
            floors[i].color = (floors[i].size < 0);
            floors[i].size = abs(floors[i].size);
        }
        
        sort(floors, floors + N);
        
        cout << max(StartWithColor(0), StartWithColor(1)) << '\n';
    }
}