#include <iostream>
#include <string>

using namespace std;

int pos[128];

struct Node
{
    Node()
    {
        next[0] = next[1] = next[2] = next[3] = NULL;
    }
    
    Node* next[4];
    
    // Will return length of commonalities with the given index
    int Add(const string & str, int index)
    {
        if (index == str.size())
            return 0;
        
        int toGoInto = pos[str[index]];
        
        if (next[toGoInto])
        {
            return next[toGoInto]->Add(str, index + 1) + 1;
        }
        else
        {
            next[toGoInto] = new Node();
            next[toGoInto]->Add(str, index + 1);
            return 0;
        }
    }
    
    void Delete()
    {
        for (int i = 0; i < 4; ++i)
        {
            if (next[i] != NULL)
            {
                next[i]->Delete();
                delete next[i];
            }
        }
    }
};


int main()
{
    pos['A'] = 0;
    pos['C'] = 1;
    pos['G'] = 2;
    pos['T'] = 3;
    
    
    int T;
    cin >> T;
    
    while (T--)
    {
        Node baseNode;
        string longest = "";
        int numOccurances;
        string phrase;
        cin >> phrase;
        
        for (int i = 0; i < phrase.size(); ++i)
        {
            int length = baseNode.Add(phrase, i);
            if (length > longest.size())
            {
                longest = phrase.substr(i, length);
                numOccurances = 2;
            }
            else if (length == longest.size())
            {
                string current = phrase.substr(i, length);
                if (current < longest)
                    longest = current;
                else if (current == longest)
                    ++numOccurances;
            }
        }
        
        if (longest == "")
            cout << "No repetitions found!\n";
        else
            cout << longest << ' ' << numOccurances << '\n';
    }
}