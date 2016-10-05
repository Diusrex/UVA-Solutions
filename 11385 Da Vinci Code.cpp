#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{
    map<int, int> fib_to_pos;
    // First 46 fit in 2^31
    int fib[50];
    fib[0] = 1; fib_to_pos[1] = 0;
    fib[1] = 2; fib_to_pos[2] = 1;
    int numFib = 2;
    while (fib[numFib - 1] > 0)
    {
        fib[numFib] = fib[numFib - 1] + fib[numFib - 2];
        fib_to_pos[fib[numFib]] = numFib;
        ++numFib;
    }
    
    
    int T;
    cin >> T;
    cin.ignore();
    int enteredFibs[150];
    while (T--)
    {
        int numFib;
        cin >> numFib;

        for (int i = 0; i < numFib; ++i)
            cin >> enteredFibs[i];
        cin.ignore();
        string line;
        getline(cin, line);
        
        string output(47, ' ');
        
        int posInFibs = 0, posInLine = 0;
        while (posInFibs < numFib)
        {
            while (posInLine < line.size() && line[posInLine] < 'A' || line[posInLine] > 'Z')
                ++posInLine;
            
            if (posInLine >= line.size())
                break;
            
            output[fib_to_pos[enteredFibs[posInFibs]]] = line[posInLine];
            ++posInFibs;
            ++posInLine;
        }
        int non_space_end = output.size() - 1;
        
        while (non_space_end >= 0 && output[non_space_end] == ' ')
        {
            --non_space_end;
        }
        
        output.resize(non_space_end + 1);
        
        cout << output << '\n';
    }
}