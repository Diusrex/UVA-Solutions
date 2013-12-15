#include <iostream>
#include <vector>

using namespace std;

struct node {
    node *leftChild;
    bool hasLeft, hasRight;
    node *rightChild;
    int value;
    
    node(int newValue)
        : hasLeft(false),
        hasRight(false),
        value(newValue)
    {
    }
};

void Assign(node* currentNode, int value)
{
    if (currentNode->value == 0)
        currentNode->value = value;
    
    else if (value < currentNode->value)
    {
        if (!currentNode->hasLeft)
        {
            node *newNode = new node(value);
            
            currentNode->leftChild = newNode;
            currentNode->hasLeft = true;
        }
        
        else
        {
            Assign(currentNode->leftChild, value);
        }
    }
    
    else
    {
        if (!currentNode->hasRight)
        {
            node *newNode = new node(value);
            
            currentNode->rightChild = newNode;
            currentNode->hasRight = true;
        }
        
        else
        {
            Assign(currentNode->rightChild, value);
        }
    }
}

void PrintOut(node* &current)
{
    if (current->hasLeft)
        PrintOut(current->leftChild);
    
    if (current->hasRight)
        PrintOut(current->rightChild);
        
    cout << current->value << '\n';
}


int main()
{
    node *baseNode = new node(0);
    
    int current; 
    
    while (cin >> current)
    {
        Assign(baseNode, current);
    }
    
    PrintOut(baseNode);
    
    return 0;
}