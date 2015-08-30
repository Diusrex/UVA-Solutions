#include <iostream>

using namespace std;

// Know that none of the integers exceed 3000

const int MAX_REMAINDER = 29999 + 5; // If the remainder is greater than 29999, then it should have been reduce earlier
int positionRemainderOccured[MAX_REMAINDER];

// Will return the total size of the repeating section
int GetRepeatingInformation(int numerator, int denominator, string &nonRepeating, string &repeating)
{
    for (int i = 0; i < MAX_REMAINDER; ++i)
        positionRemainderOccured[i] = -1;
    
    int previousRemainder = (numerator % denominator) * 10;
    
    string digits = "";
    while (positionRemainderOccured[previousRemainder] == -1) // TODO: Ensure is correct....
    {
        int currentDigit = previousRemainder / denominator;
        positionRemainderOccured[previousRemainder] = digits.size();
        previousRemainder %= denominator;
        digits += ('0' + currentDigit);
        
        previousRemainder *= 10;
    }
    
    int startOfRepeating = positionRemainderOccured[previousRemainder];
    int repeatingSize = digits.size() - startOfRepeating;
    if (digits.size() > 50)
    {
        digits = digits.substr(0, 50) + "...";
    }
    nonRepeating = digits.substr(0, startOfRepeating);
    repeating = digits.substr(startOfRepeating);
    
    
    return repeatingSize;
}

int main()
{
    int numerator, denominator;
    string nonRepeating, repeating;
    while (cin >> numerator >> denominator)
    {
        int len = GetRepeatingInformation(numerator, denominator, nonRepeating, repeating);
        
        cout << numerator << "/" << denominator << " = " << numerator / denominator << '.' << nonRepeating << "(" << repeating << ")" << '\n';
        cout << "   " << len << " = number of digits in repeating cycle\n\n";
    }
}