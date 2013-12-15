#include <iostream>
#include <string>

using namespace std;

int main()
{
    int numOfGroups;
    cin >> numOfGroups;
    
    while (numOfGroups)
    {
        string phrase;
        
        cin >> phrase;
        
        int size = phrase.size();
        int groupSize = size / numOfGroups;
        for (int i = 0; i < size; i += groupSize)
        {
            
            for (int z = i, p = i + groupSize - 1; z < p; ++z, --p)
            {
                char temp(phrase[z]);
                phrase[z] = phrase[p];
                phrase[p] = temp;
            }
        }
        
        cout << phrase << '\n';
        
        cin >> numOfGroups;
    }


}