#include <iostream>
#include <string>

using namespace std;

struct node
{
    char character;
    node* next;
    
    node()
        : next(NULL)
    {}
    
    void remove()
    {
        if (next != NULL)
        {
            next->remove();
            delete next;
        }
    }
};

struct linked_list
{
    linked_list()
        : head(NULL),
        tail(NULL) 
    {}
        
    node *head, *tail;
    
    void clean()
    {
        if (head != NULL)
        {
            head->remove();
            delete head;
        }
    }
};

void PrintOut(const linked_list& list)
{
    const node* current = list.head;
    while (current != NULL)
    {
        cout << current->character;
        current = current->next;
    }
    
    cout << '\n';
}

int main()
{
    string line;
    
    while (cin >> line)
    {
        string::const_iterator iter = line.begin();
        
        const string::const_iterator end = line.end();
        
        while (iter != end && (*iter == '[' || *iter == ']' ))
            ++iter;
        
        // Only consisted of [ and ]
        if (iter == end)
        {
            cout << '\n';
            continue;
        }
        
        linked_list list;
        
        node* current = new node;
        current->character = *iter;
        
        ++iter;
        list.head = current;
        list.tail = current;
        
        bool isAtStart(false);
        
        for (; iter != line.end(); ++iter)
        {
            if (*iter == '[')
                isAtStart = true;
            else if (*iter == ']')
            {
                isAtStart = false;
                current = list.tail;
            }
            else
            {
                node* newNode = new node;
                newNode->character = *iter;
                
                if (isAtStart)
                {
                    node* temp = list.head;
                    list.head = newNode;
                    newNode->next = temp;
                    isAtStart = false;
                }
                
                else
                {
                    if (current == list.tail)
                        list.tail = newNode;
                    else
                        newNode->next = current->next;
                    
                    current->next = newNode;  
                }
                
                current = newNode;
            }
        }
        PrintOut(list);
        
        
        list.clean();
    }
}