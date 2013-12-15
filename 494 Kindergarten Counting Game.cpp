#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss;
        ss << line;
        
        int count(0);
        while (ss >> line) { 
            bool works(false);
            
            for (int i = 0; i < line.size(); ++i)
            {
                if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
                {
                    if (!works)
                        ++count;
                    works = true;
                }
                
                else
                    works = false;
            }
            
        }
        
        cout << count << '\n';      
    
    }

}