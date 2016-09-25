#include <iostream>

using namespace std;

const int Max = 10000;
bool encountered[Max];

int GetCount(int num)
{
    for (int i = 0; i < Max; ++i)
    {
        encountered[i] = false;
    }
    
    int count = 0;
    
    while (!encountered[num])
    {
        ++count;
        encountered[num] = true;
        
        
        // Square it
        num *= num; 
        // Take the middle 4 digits -> 2 off from each end
        num /= 100;
        num %= Max;
    }
    
    return count;
}

int main()
{
    int num;
    while (cin >> num, num)
    {
        cout << GetCount(num) << '\n';
    }
}
