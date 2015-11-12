#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

// Precalculated using the Calculate function below
vector<int> uniqueNumbers[4] = {
    {0, 1, 81},
    {0, 1, 2025, 3025, 9801},
    {0, 1, 88209, 494209, 998001},
    {0, 1, 4941729, 7441984, 24502500, 25502500, 52881984, 60481729, 99980001}};


void Calculate()
{
    int current = 0;
    int top = 100;
    int split = 10;
    for (int i = 0; i < 4; ++i)
    {
        for (current = 0; current < top; ++current)
        {
            int lhs = current % split;
            int rhs = current / split;
            int sum = lhs + rhs;
            
            if (sum * sum == current)
            {
                cout << lhs << ' ' << rhs << ' ' << current << '\n';
            }
            
        }
        
        cout << current << '\n';
        top *= 100;
        split *= 10;
    }
}



int main()
{
    //Calculate();
    
    int digits;
    
    while (cin >> digits)
    {
        int index = digits / 2 - 1;
        
        for (auto val : uniqueNumbers[index])
            cout << setw(digits) << setfill('0') << val << '\n';
    }
}