#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int D, N;
string baseNum;

// Stores the position of the highest
int highest[500000];

// Is inclusive
int Create(int node, int left, int right)
{
    if (node == -1)
        return 0;
    
    if (left == right)
        return left;
    
    int mid = (left + right) / 2;
    
    highest[node] = Create(node * 2, left, mid);
    
    if (mid + 1 < D)
    {
        int rPos = Create(node * 2 + 1, mid + 1, right);
        
        if (baseNum[highest[node]] < baseNum[rPos])
            highest[node] = rPos;
    }
    
    return highest[node];
}

// Left and right are for the current node
// Will return the index of the highest
int FindHighest(int node, int left, int right, int intervalLeft, int intervalRight)
{
    if (left == right)
        return left;
    
    if (left >= intervalLeft && right <= intervalRight)
        return highest[node];
    
    int bestPos = intervalLeft;
    int mid = (left + right) / 2;
    if (left <= intervalRight && mid >= intervalLeft)
    {
        int otherPos = FindHighest(node * 2, left, mid, intervalLeft, intervalRight);
        if (baseNum[otherPos] > baseNum[bestPos])
            bestPos = otherPos;
    }
    
    if (mid + 1 <= intervalRight && right >= intervalLeft)
    {
        int otherPos = FindHighest(node * 2 + 1, mid + 1, right, intervalLeft, intervalRight);
        if (baseNum[otherPos] > baseNum[bestPos])
            bestPos = otherPos;
    }
    
    return bestPos;
}
// Want to select the highest that I can, starting from the right.
    // Ex: If there are 481111 and I need to remove 1 digit, remove the 4

int main()
{
    string newNum;
    
    while (cin >> D >> N, D)
    {
        cin >> baseNum;
        Create(1, 0, D - 1);
        int size = D - N;
        newNum.resize(D  - N);
        
        int lastUsed = -1;
        
        for (int pos = 0; pos < size; ++pos)
        {
            int start = lastUsed + 1;
            int numLeft = size - pos;
            
            int end = D - numLeft;
            
            int newPos = FindHighest(1, 0, D - 1, start, end);
            newNum[pos] = baseNum[newPos];
            lastUsed = newPos;
        }
        
            
        cout << newNum << '\n';
    }
}