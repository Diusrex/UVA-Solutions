#include <iostream>
#include <vector>
#include <algorithm>

#define Load(array, size) for (int q = 0; q < size; ++q) cin >> array[q];

using namespace std;

int main()
{
    int size;
    
    vector<int> actual, guess;
    
    int t(0), strong, weak;
    
    while (cin >> size, size)
    {
        ++t;
        
        actual.resize(size);
        guess.resize(size);
        
        Load(actual, size);
        
        cout << "Game " << t << ":\n";
        
        Load(guess, size);
        
        while (guess[0])
        {
            strong = weak = 0;
            
            vector<int> numberUnmatchA(10, 0), numberUnmatchG(10, 0);
            
            for (int i = 0; i < size; ++i)
            {
                if (guess[i] == actual[i])
                    ++strong;
                
                else
                {
                    ++numberUnmatchA[actual[i]];
                    ++numberUnmatchG[guess[i]];
                }
            }
            
            for (int i = 1; i < 10; ++i)
                weak += min(numberUnmatchA[i], numberUnmatchG[i]);
            
            cout << "    (" << strong << ',' << weak << ")\n";
            
            Load(guess, size);
        }
    }
}