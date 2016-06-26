#include <iostream>
#include <string>

using namespace std;

bool Match(int indexIntoFirst, const string &first, const string &second)
{
    int i = indexIntoFirst, j = 0;
    
    for (; i < first.size() && j < second.size(); ++i, ++j)
    {
        if (first[i] == '2' && second[j] == '2')
            return false;
    }
    
    
    return true;
}

int main()
{
    string first, second;
    while (cin >> first >> second)
    {
        int indexIntoFirst = 0;
        
        for (; indexIntoFirst < first.size(); ++indexIntoFirst)
            if (Match(indexIntoFirst, first, second))
                break;
        
        int indexIntoSecond = 0;
        
        for (; indexIntoSecond < second.size(); ++indexIntoSecond)
            if (Match(indexIntoSecond, second, first))
                break;
        
        cout << min(max(second.size() + indexIntoFirst, first.size()),
                    max(first.size() + indexIntoSecond, second.size())) << '\n';
    }
}