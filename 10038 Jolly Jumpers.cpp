#include <iostream>
#include <vector>

using namespace std;

// Find the position where  a[x - 1] < a[x] = temp < a[x + 1] (or end of array)
    // if is equal to either, no need to do any operations
void PutInSorted(vector<int>& array, int number)
{
    if (array.size() == 0)
        array.push_back(number);
        
    int numberOfElements = array.size() - 1;
    
    int bottom(0), top(numberOfElements), mid(numberOfElements/2);
    
    while (bottom <= top)
    {
        if (array[mid] > number)
            top = mid - 1;
        if (array[mid] < number)
            bottom = mid + 1;
        
        // No need to reorder
        if (array[mid] == number)
            return;
            
        mid = (top - bottom + 1) / 2 + bottom;
        
    }
    
    if (array[bottom] == number)
        return;
        
    array.push_back(number);
    
    for (int z = numberOfElements + 1; z > mid; --z)
    {
        int temp(array[z]);
        array[z] = array[z - 1];
        array[z - 1] = temp;   
    }
}


int main()
{
    int n;
        
    while (cin >> n)
    {
        vector<bool> diffDone(n - 1, false);
        
        

        int previousValue;
        cin >> previousValue;
        
        for (int i = 1; i < n; ++i)
        {
            int temp;
            cin >> temp;
            
            if (temp - previousValue >= 0)
                diffDone[temp - previousValue] = true;
                
            else
                diffDone[previousValue - temp] = true;
                
            previousValue = temp;      
        }
        
        bool allTrue(true);
        
        for (int i = 1; i < n; ++i)
        {
            if (!diffDone[i])
                allTrue = false;
        }
                
        if (allTrue)
            cout << "Jolly\n";
        
        else
            cout << "Not jolly\n";
    
    }
}
