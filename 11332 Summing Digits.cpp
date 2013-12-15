#include <iostream>

using namespace std;

int getG(int n)
{
    if (n / 10 == 0)
        return n;
    
    else
    {
        int newNum(0);
        
        while (n)
        {
            newNum += n % 10;
            n /= 10;
        }
        
        return getG(newNum);
    }
}


int main()
{
    int num;
    
    cin >> num;
    
    while (num != 0)
    {
        cout << getG(num) << '\n';
        cin >> num;    
    }


}