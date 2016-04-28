#include <iostream>

using namespace std;

// Know that none of the integers exceed 1000

const int MAX_REMAINDER = 9999 + 5; // If the remainder is greater than 9999, then it should have been reduce earlier
int positionRemainderOccured[MAX_REMAINDER];

// Will return the total size of the repeating section
int GetRepeatingInformation(int numerator, int denominator, string &digits)
{
    for (int i = 0; i < MAX_REMAINDER; ++i)
        positionRemainderOccured[i] = -1;
    
    int previousRemainder = (numerator % denominator) * 10;
    while (previousRemainder && positionRemainderOccured[previousRemainder] == -1)
    {
        int currentDigit = previousRemainder / denominator;
        positionRemainderOccured[previousRemainder] = digits.size();
        previousRemainder %= denominator;
        digits += ('0' + currentDigit);
        
        previousRemainder *= 10;
    }
    
    if (previousRemainder == 0)
        return 0;
    
    int startOfRepeating = positionRemainderOccured[previousRemainder];
    int repeatingSize = digits.size() - startOfRepeating;
    
    return repeatingSize;
}

int main()
{
    int numerator, denominator;
    string digits;
    while (cin >> numerator >> denominator, denominator)
    {
        digits = ".";
        int len = GetRepeatingInformation(numerator, denominator, digits);
        
        int startPos = 0;
        while (digits.size() > startPos)
        {
            cout << digits.substr(startPos, 50) << '\n';
            startPos += 50;
        }
        if (len == 0)
            cout << "This expansion terminates.\n\n";
        else
            cout << "The last " << len << " digits repeat forever.\n\n";
    }
}