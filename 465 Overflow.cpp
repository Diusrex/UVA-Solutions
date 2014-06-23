#include <iostream>
#include <sstream>

// Could be improved with better heuristics -> No point in try to see if 0 + 0 would go over.

using namespace std;

int main()
{
    string maxString = "2147483647";
    long long maxNum = 2147483647;
    
    string first, second;
    char oper;
    
    
    while (cin >> first >> oper >> second)
    {
        cout << first << ' ' << oper << ' ' << second << '\n';
        
        while (first[0] == '0' && first.size() != 1)
            first.erase(first.begin());
        
        while (second[0] == '0' && second.size() != 1)
            second.erase(second.begin());
            
        bool firstTooLarge = (first.size() > maxString.size() || (first.size() == maxString.size() && first > maxString));
        bool secondTooLarge = (second.size() > maxString.size() || (second.size() == maxString.size() && second > maxString));
        
        if (firstTooLarge)
            cout << "first number too big\n";
        if (secondTooLarge)
            cout << "second number too big\n";
        
        if (oper == '+')
        {
            if (firstTooLarge || secondTooLarge)
                cout << "result too big\n";
            else
            {
                std::stringstream ss;
                ss << first << ' ' << second;
                long long f, s;
                ss >> f >> s;
                
                if (f + s > maxNum)
                    cout << "result too big\n";
            }
        }
        
        else // oper == '*'
        {
            if (first != "0" && second != "0")
            {
                if (firstTooLarge || secondTooLarge)
                    cout << "result too big\n";
                
                else
                {
                    std::stringstream ss;
                    ss << first << ' ' << second;
                    long long f, s;
                    ss >> f >> s;
                    
                    if (f * s > maxNum)
                        cout << "result too big\n";
                }
            }
        }
    }
}