#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        string line;
        cin >> line;
        int count = 0;
        int previous = 0;
        
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == 'O')
            {
                ++previous;
                count += previous;
            }
            else
                previous = 0;
        }
        
        cout << count << '\n';
    }
}