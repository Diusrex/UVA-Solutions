#include <iostream>
#include <set>

using namespace std;

int elementsAdded[30005];
int getsAfter[30005];

multiset<int> numbers;
multiset<int>::iterator currentElement;

int main()
{
    int K;
    cin >> K;
    
    string sep = "";
    while (K--)
    {
        cout << sep;
        sep = "\n";
        
        int M, N;
        cin >> M >> N;
        
        for (int i = 0; i < M; ++i)
            cin >> elementsAdded[i];
        for (int i = 0; i < N; ++i)
            cin >> getsAfter[i];
        
        numbers.clear();
        numbers.insert(elementsAdded[0]);
        currentElement = numbers.begin();
        
        int indexInGets = 0;
        for (int num = 1; num < M; ++num)
        {
            bool increase = false;
            while (indexInGets < N && getsAfter[indexInGets] == num)
            {
                ++indexInGets;
                cout << *currentElement << '\n';
                ++currentElement;
            }
            
            numbers.insert(elementsAdded[num]);
            if (currentElement == numbers.end() || elementsAdded[num] < *currentElement)
            {
                --currentElement;
            }
            
        }
        while (indexInGets < N && getsAfter[indexInGets] == M)
        {
                ++indexInGets;
                cout << *currentElement << '\n';
                ++currentElement;
        }
    }
}