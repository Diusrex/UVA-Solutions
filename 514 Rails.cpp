#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    string sep = "";
    while (cin >> N, N)
    {
        int current;
        stack<int> s;
        while (cin >> current, current)
        {
            while (!s.empty())
                s.pop();
            
            int numAdded = 1;
            bool possible = true;
            
            s.push(numAdded++);
            
            while (s.top() != current)
                s.push(numAdded++);
            
            possible = (s.top() == current);
            s.pop();
            
            for (int numLoaded = 1; numLoaded < N; ++numLoaded)
            {
                cin >> current;
                
                if (possible)
                {
                    if (s.empty())
                        s.push(numAdded++);
                    
                    while (s.top() != current && numAdded <= N)
                        s.push(numAdded++);
                    
                    possible = (s.top() == current);
                    
                    s.pop();
                }
            }
            
            cout << (possible ? "Yes\n" : "No\n");
        }
        
        cout << '\n';
    }
}