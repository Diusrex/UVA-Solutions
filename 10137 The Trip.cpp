#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int students[1005];

int main()
{
    int N;
    
    while (cin >> N, N)
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            int dollar, cent;
            char temp;
            cin >> dollar >> temp >> cent;
            students[i] = dollar * 100 + cent;
            sum += students[i];
        }
        
        int lowAverage = sum / N;
        int highAverage = lowAverage + ((sum % N) ? 1 : 0);
        int sumAbove = 0;
        
        for (int i = 0; i < N; ++i)
        {
            if (students[i] > highAverage)
                sumAbove += students[i] - highAverage;
        }
        
        int sumBelow = 0;
        for (int i = 0; i < N; ++i)
        {
            if (students[i] < lowAverage)
                sumBelow += lowAverage - students[i];
        }
        
        int usedSum = max(sumAbove, sumBelow);
        
        
        cout << '$' << (usedSum / 100) << '.' << setw(2) << setfill('0') << (usedSum % 100) << '\n';
    }
}