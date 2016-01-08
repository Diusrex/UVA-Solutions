#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned long long ull;

// Binary search....
// Need to handle special case where possible no one will get a book....
    // Will happen:
    // 5 books, 3 people:
    // 10 10 50 100

using namespace std;

int M, K;

ull pages[501];
bool isFinalBook[501];

bool CanMatchBooks(int maxNumPages)
{
    ull pagesForCurrent = 0, numberUsed = 0;
    for (int book = M - 1; book >= 0; --book)
    {
        if (pages[book] + pagesForCurrent > maxNumPages)
        {
            ++numberUsed;
            if (numberUsed == K)
                return false;
            pagesForCurrent = pages[book];
        }
        else
        {
            pagesForCurrent += pages[book];
        }
    }
    
    return true;
}

ull GetMinimumPagesAssigned(ull sum, ull largest)
{
    // [min, max]
    ull min = largest, max = sum;
    
    while (min != max)
    {
        // Want to round up. Otherwise could encounter infinite loop
        ull middle = min + (max - min) / 2;
        if (CanMatchBooks(middle))
            max = middle;
        
        else
            min = middle + 1;
    }
    
    return min;
}

void BreakdownBooks(ull maximumPages)
{
    ull pagesForCurrent = 0, currentScribe = K - 1;
    
    
    for (int book = M - 1; book >= 0; --book)
    {
        if (pages[book] + pagesForCurrent > maximumPages || // Can't do any more pages
            currentScribe == book + 1) // There are as many books left as are scribess
        {
            --currentScribe;
            
            isFinalBook[book] = true;
            pagesForCurrent = 0;
        }
        
        pagesForCurrent += pages[book];
    }
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        cin >> M >> K;
        ull sum = 0, largest = 0;
        for (int i = 0; i < M; ++i)
        {
            isFinalBook[i] = false;
            
            cin >> pages[i];
            sum += pages[i];
            
            largest = max(largest, pages[i]);
        }
        
        // Ensure Min is based off of the largest book, while max is the total number of pages
        
        ull maxPages = GetMinimumPagesAssigned(sum, largest);
        
        BreakdownBooks(maxPages);
        
        cout << pages[0];
        if (isFinalBook[0])
            cout << " /";
        
        for (int i = 1; i < M; ++i)
        {
            cout << ' ' << pages[i];
            if (isFinalBook[i])
                cout << " /";
        }
        
        cout << '\n';
    }
}