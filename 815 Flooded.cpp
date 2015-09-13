#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

const double ACCURACY = 0.001;

double GetVolumeUsed(double wantedHeight, const vector<int> & heights)
{
    double volume = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        double diff = wantedHeight - heights[i];
        if (diff > 0)
            volume += diff;
    }
    
    return volume *= 100;
}

double FindLowestHeight(const vector<int> & heights)
{
    int lowest = heights[0];
    for (int i = 1; i < heights.size(); ++i)
        if (heights[i] < lowest)
            lowest = heights[i];
        
    return lowest;
}
double FindHeight(const vector<int> &heights, const int waterVolume)
{
    double largestHeight = numeric_limits<int>::max();
    double smallestHeight = FindLowestHeight(heights);
    double middleHeight;
    double volumeUsed;
    
    while (middleHeight = (largestHeight + smallestHeight) / 2, volumeUsed = GetVolumeUsed(middleHeight, heights), abs(volumeUsed - waterVolume) > ACCURACY)
    {
        if (volumeUsed < waterVolume)
            smallestHeight = middleHeight;
        else
            largestHeight = middleHeight;
    }
    
    return middleHeight;
}

double GetPercent(double height, const vector<int> &heights)
{
    int count = 0;
    for (int i = 0; i < heights.size(); ++i)
    {
        if (heights[i] < height)
            ++count;
    }
    return 100.0 * count / heights.size();
}

int main()
{
    int m, n, T = 1;
    while (cin >> m >> n, m)
    {
        vector<int> heights(m * n);
        for (int i = 0; i < heights.size(); ++i)
        {
            cin >> heights[i];
        }
        
        int volume;
        cin >> volume;
        
        double height = FindHeight(heights, volume);
        
        cout << "Region " << T++ << '\n';
        cout << "Water level is " << setprecision(2) << std::fixed << height << " meters.\n";
        cout << setprecision(2) << std::fixed << GetPercent(height, heights) << " percent of the region is under water.\n\n";
    }
}