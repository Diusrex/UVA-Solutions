#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// So basically, want 6 numbers out of the given set
const int NUMBER_NEEDED = 6;

int N;

void PrintOut(const vector<int> &toPrint)
{
    cout << toPrint[0];
    
    for (int i = 1; i < NUMBER_NEEDED; ++i)
        cout << ' ' << toPrint[i];
    
    cout << '\n';
}
    
void CreateAndPrintSubset(int numIncluded, int pos,
    const vector<int> &sortedNumbers, vector<int> &toPrint)
{
    // TODO: Correct?
    if (numIncluded + N - pos < NUMBER_NEEDED)
        return;
    
    if (pos == N)
    {
        if (numIncluded == NUMBER_NEEDED)
            PrintOut(toPrint);
        
        return;
    }
    
    if (numIncluded < NUMBER_NEEDED)
    {
        toPrint[numIncluded] = sortedNumbers[pos];
        CreateAndPrintSubset(numIncluded + 1, pos + 1, sortedNumbers, toPrint);
    }
    
    CreateAndPrintSubset(numIncluded, pos + 1, sortedNumbers, toPrint);
}

int main()
{
    vector<int> numbers(15);
    vector<int> toPrint(6);
    
    string sep = "";
    
    while (cin >> N, N)
    {
        cout << sep;
        sep = "\n";
        
        for (int i = 0; i < N; ++i)
            cin >> numbers[i];
        
        sort(numbers.begin(), numbers.begin() + N);
        
        CreateAndPrintSubset(0, 0, numbers, toPrint);
    }
}