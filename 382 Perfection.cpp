#include <iostream>
#include <iomanip>

using namespace std;

string Output(int num)
{
    int sum = 0;
    
    for (int current = 1; current < num; ++current)
    {
        if (num % current == 0)
        {
            sum += current;
            if (sum > num)
                return "ABUNDANT\n";
        }
    }
    
    if (sum == num)
        return "PERFECT\n";
    return "DEFICIENT\n";
}

int main()
{
    cout << "PERFECTION OUTPUT\n";
    
    int num;
    while (cin >> num, num)
        cout << setw(5) << num << "  " << Output(num);
    
    cout << "END OF OUTPUT\n";
}