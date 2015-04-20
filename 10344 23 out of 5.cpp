#include <iostream>
#include <algorithm>

using namespace std;

const int NumNumbers = 5;
const double eps = 0.5;

int numbers[NumNumbers];

bool Possible(int total, int pos)
{
    if (pos == NumNumbers)
        return total == 23;
    
    int num = numbers[pos];
    
    return Possible(total + num, pos + 1) 
        || Possible(total - num, pos + 1)
        || Possible(total * num, pos + 1);
}

void ReadNumbers()
{
    for (int i = 0; i < NumNumbers; ++i)
        cin >> numbers[i];
}

bool NotAllZero()
{
    for (int i = 0; i < NumNumbers; ++i)
        if (numbers[i])
            return true;
    
    return false;
}

int main()
{
    while (ReadNumbers(), NotAllZero())
    {
        sort(numbers, numbers + NumNumbers);
        bool possible = false;
        do {
            possible = Possible(numbers[0], 1);
            if (possible)
                break;
        } while (next_permutation(numbers, numbers + NumNumbers));
        
        if (possible)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}