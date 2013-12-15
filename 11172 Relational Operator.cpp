#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int first, second;
        cin >> first >> second;
        
        if (first < second)
            cout << "<\n";
        
        else if (first > second)
            cout << ">\n";
        
        else
            cout << "=\n";
    
    }
}