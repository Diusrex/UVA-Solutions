#include <iostream>
#include <vector>

using namespace std;

string number;

inline int Convert(char c)
{
    return c - '0';
}

bool CanBeReduced(int value, const vector<int> & countsLeft)
{
    for (int i = value - 1; i >= 0; --i)
        if (countsLeft[i])
            return true;
        
    return false;
}

// TODO: Needs to keep in mind possibility of overflowing to reduce
    // EG: 2210102960
    //         ^ change to 0, increase everything else
    // So would be possible if there are not 2 zeros right after?
        // Or sum of (zeros following <= countsLeft)

// Reduce the highest counts left for each
// Includes the actual number, for if it will need to be reduced
// NOTE: No need to call if have already reduced. Know will be possible, and will just go with largest to smallest numbers
bool RestCanBeDoneWithoutReducingCurrent(int start, vector<int> countsLeft)
{
    // If there are not spots left for the current digit, need to reduce
    if (!countsLeft[Convert(number[start])])
        return false;
    
    --countsLeft[Convert(number[start])];
    
    // Otherwise, know it is possible if can reduce at least one digit following this
    for (int i = start + 1; i < number.size(); ++i)
    {
        int digitValue = Convert(number[i]);
        // Can reduce this digit with no problems
        if (CanBeReduced(digitValue, countsLeft))
        {
            return true;
        }
        
        // Able to keep this digit the same
        else if (countsLeft[digitValue])
        {
            --countsLeft[digitValue];
        }
        
        // Impossible for this digit
        else
            return false;
    }
    
    return true;
}

string GetBest()
{
    // Each has 2 counts left
    vector<int> counts(10, 2);
    
    int pos = 0;
    string newNum = "";
    for (; pos < number.size() && RestCanBeDoneWithoutReducingCurrent(pos, counts); ++pos)
    {
        // Keep the value the same at pos
        newNum += number[pos];
        --counts[Convert(number[pos])];
    }
    
    if (pos == number.size())
        return newNum;
    
    // First, reduce the value
    // Can assume isn't 0, since that is impossible to reduce for this guy, so it wouldn't be encountered
    // So only special case is when it has a leading 1, and there are no newNum
    if (number[pos] != '1' || newNum != "")
    {
        int newNumValue = Convert(number[pos]) - 1;
        while (!counts[newNumValue])
            --newNumValue;
        // Know will never go below 0, so don't need to worry about that
        --counts[newNumValue];
        newNum += ('0' + newNumValue);
    }
    
    // Always move one 'further' in the list
    ++pos;
    
    // Maximize the rest
    for (int tried = 9; pos < number.size(); ++pos)
    {
        while (!counts[tried])
            --tried;
        --counts[tried];
        newNum += ('0' + tried);
    }
    
    return newNum;
}

int main()
{
    while (cin >> number)
    {
        cout << GetBest() << '\n';
    }
}