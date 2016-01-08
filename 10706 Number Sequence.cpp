#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

// Exclusive
const int MaxIndex = 31268;

// To search:
    // Binary search on lengthBefore, to cut out most
    // Then binary search on lengthOf for rest. Can use the digit in that equal to the diff of rest and lengthOf[i]
    // The number added is the index to access
// the lengthOf[i] is the length of i added to lengthOf[i - 1]
int lengthBefore[MaxIndex + 5];
int lengthOf[MaxIndex + 5];

int getNumDigits(ull currentHighest)
{
    int numDigits = 0;
    while (currentHighest)
    {
        ++numDigits;
        currentHighest /= 10;
    }
    
    return numDigits;
}

void GenerateData()
{
    int i = 1, totalLength = 0, currentLength = 1;
    
    while (i < MaxIndex)
    {
        totalLength += currentLength;
        lengthBefore[i] = totalLength;
        lengthOf[i] = currentLength;
        
        ++i;
        currentLength += getNumDigits(i);
    }
}


int GetNumber(int position)
{
    // Want lower, because will decrease index by 1 so it doesn't exactly match
    int * nextOne = lower_bound(lengthBefore, lengthBefore + MaxIndex, position);
    
    position -= *(nextOne - 1);
    
    // Now, find the addition number that it is part of:
    // Want lower, because need to use the first one that is at least as long as it.
        // This ensures that it is part of i, where i is lengthOf[i] found by the lower_bound
    int * numberLengthOf = lower_bound(lengthOf, lengthOf + MaxIndex, position);
    
    // This is the index, which is also the actual value of it
    int numberPartOf = numberLengthOf - lengthOf;
    int totalDigits = getNumDigits(numberPartOf);
    
    // How far past the previous entry it is
    int positionInNumberFromFront = position - *(numberLengthOf - 1);
    
    int digitsToRemove = totalDigits - positionInNumberFromFront;
    
    while (digitsToRemove)
    {
        numberPartOf /= 10;
        --digitsToRemove;
    }
    
    return numberPartOf % 10;
}

int main()
{
    GenerateData();
    
    int T;
    cin >> T;
    
    while (T--)
    {
        int pos;
        cin >> pos;
        
        cout << GetNumber(pos) << '\n';
    }
}