#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

int N;
int numbers[22];
int SideLength;
int start;

bool CreateNewBunch(int included);

bool CanCreateUsingAll(int index, int currentLength, int included)
{
    if (currentLength == SideLength)
    {
        return CreateNewBunch(included);
    }
    
    for (int i = index; i < N; ++i)
        if (!(included & (1 << i)) && currentLength + numbers[i] <= SideLength)
        {
            if (CanCreateUsingAll(i + 1, currentLength + numbers[i], included | (1 << i)))
            {
                return true;
            }
            // Skip equal lengths
            while (numbers[i] == numbers[i + 1])
                ++i;
        }
    
    return false; 
}


bool CreateNewBunch(int included)
{
    for (int i = start; i < N; ++i)
        if (!(included & (1 << i)))
        {
            return CanCreateUsingAll(i + 1, numbers[i], included | (1 << i));
        }
        
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> N;
        int sum = 0, largest = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> numbers[i];
            sum += numbers[i];
            largest = max(largest, numbers[i]);
        }
        
        sort(numbers, numbers + N, greater<int>());
        
        SideLength = sum / 4;
        start = 0;
        for (; numbers[start] == SideLength; ++start)
            ;
        
        if (sum % 4 == 0 && largest <= SideLength && (start == N || CreateNewBunch((1 << start) - 1)))
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
    }
}