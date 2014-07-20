#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    string phrase;
    
    int first;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> first >> phrase;
        
        double cost = first * 0.5;
        if (phrase.size() >= 4 && phrase[3] != ' ')
            cost += (phrase[3] - '0') * 0.05;
            
        cout << "Case " << t << ": " << cost << '\n';
    }
    
}