#include <iostream>
#include <string>

using namespace std;

// Whenever they are different, can assume is one move
// However, for every pair 0 -> 1 and 0 -> 1, can use one move to fix both

int GetTotal(const string &str1, const string &str2)
{
    int overallDiff = 0;
    int oneDiff = 0;
    int numberOneToZero = 0, numberZeroToOne = 0;
    
    for (int i = 0; i < str1.size(); ++i)
    {
        if (str1[i] != str2[i])
            ++overallDiff;
        if (str1[i] == '?' && str2[i] == '1')
            --oneDiff;
        else if (str1[i] == '0' && str2[i] == '1')
        {
            ++numberZeroToOne;
            --oneDiff;
        }
        else if (str1[i] == '1' && str2[i] == '0')
        {
            ++numberOneToZero;
            ++oneDiff;
        }
    }
    
    if (oneDiff > 0)
        return -1;
    
    return overallDiff - min(numberOneToZero, numberZeroToOne);
}

int GetCount(const string &str, char chr)
{
    int count = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == chr)
            ++count;
    return count;
}

int main()
{
    string str1, str2;
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> str1 >> str2;
        
        cout << "Case " << t << ": " << GetTotal(str1, str2) << '\n';
    }
}