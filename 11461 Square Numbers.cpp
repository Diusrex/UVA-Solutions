#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int bot, top;
    
    cin >> bot >> top;
    
    while (bot)
    {
        int count(0);
        
        int num = sqrt(bot);
        if (num*num < bot)
            ++num;
        
        
        for (;num*num <= top; ++num, ++count); 
        
        cout << count << '\n';
        cin >> bot >> top;
    }
}