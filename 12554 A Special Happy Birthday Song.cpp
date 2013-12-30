#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    const int size = 16;
    string words[size] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };
    
    
    
    
    int numPeople;
    cin >> numPeople;
    
    vector<string> names(numPeople);
    
    for (int i = 0; i < numPeople; ++i)
        cin >> names[i];
    
    bool allGone = false;
    
    for (int person = 0, cWord = 0; cWord < size || !allGone; ++person, ++cWord)
    {
        cWord %= size;
        cout << names[person] << ": " << words[cWord] << '\n';
        
        if (person + 1 == numPeople)
        {
            allGone = true;
            person = -1;
        }
    }
}