#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

struct card {
    pair<char, char> value;
    vector<card*> predecessors;
};

int main()
{
    
    int n;
    
    cin >> n;
    
    while (n)
    {
        int count(0);
        
        card* baseNode = new card;
        
        for (int i = 0; i < n; ++i)
        {
            int numOfCards;
            cin >> numOfCards;
            
            vector<pair<char, char> > tempPairs(numOfCards);
            
            for (int z = 0; z < numOfCards; ++z)
            {
                char num, suit;
                cin >> num;
                if (num == '1')
                    cin >> num;
                cin >> suit;
                tempPairs[z] = make_pair(num, suit);
            }
            
            // This stands for tail
            tempPairs.push_back(make_pair('T', 0));
            
            int z = numOfCards;
            
            card* current = baseNode;
            
            for (; z > 0; --z)
            {
                bool match(false);
            
                for (vector<card*>::const_iterator iter = current->predecessors.begin(); iter != current->predecessors.end(); ++iter)
                    if ((*iter)->value == tempPairs[z - 1])
                    {
                        match = true;
                        current = *iter;
                        break;
                    }
                    
                if (!match)
                    break;
                
            }
            
            count += z;
            
            for (;z >0; --z)
            {
                card* newNode = new card;
                newNode->value = tempPairs[z - 1];
                current->predecessors.push_back(newNode);
                current = newNode;
            }
        }
        
        cout << count << '\n';
        cin >> n;
    }

}