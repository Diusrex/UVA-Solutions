#include <iostream>
#include <string>

using namespace std;

int valueMapping[26];

int main()
{
    int T;
    cin >> T;
    
    string num;
    
    valueMapping['B' - 'A'] = 1;
    valueMapping['U' - 'A'] = 10;
    valueMapping['S' - 'A'] = 100;
    valueMapping['P' - 'A'] = 1000;
    valueMapping['F' - 'A'] = 10000;
    valueMapping['T' - 'A'] = 100000;
    valueMapping['M' - 'A'] = 1000000;
    
    while (T--)
    {
        cin >> num;
        long long total = 0;
        int countOfSame = 0;
        int currentValue;
        int previousValue = valueMapping[num[0] - 'A'];
        bool increasing = true, decreasing = true, highCount = false;
        
        for (string::iterator iter = num.begin(); iter != num.end(); ++iter)
        {
            currentValue = valueMapping[*iter - 'A'];
            if (currentValue > previousValue)
            {
                decreasing = false;
                countOfSame = 1;
                previousValue = currentValue;
            }
            else if (currentValue < previousValue)
            {
                increasing = false;
                countOfSame = 1;
                previousValue = currentValue;
            }
            else
            {
                ++countOfSame;
                if (countOfSame == 10)
                {
                    highCount = true;
                    break;
                }
            }
            
            total += currentValue;
        }
        
        if ((increasing || decreasing) && !highCount)
            cout << total << '\n';
        else
            cout << "error\n";
    }
}