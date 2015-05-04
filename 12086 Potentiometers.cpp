#include <iostream>

using namespace std;

int total[600015];
int base[200005];

// Both left and right are inclusive

int Generate(int node, int left, int right)
{
    if (left == right)
        return base[left];
    
    int mid = (left + right) / 2;
    
    return total[node] = 
        Generate(node * 2, left, mid) + Generate(node * 2 + 1, mid + 1, right);
}

int Set(int currentNode, const int wantedBase, const int valueToUse, int left, int right)
{
    if (left == right)
    {
        int diff = valueToUse - base[left];
        base[left] = valueToUse;
        
        return diff;
    }
    
    int mid = (left + right) / 2;
    int diff;
    if (wantedBase <= mid)
        diff = Set(currentNode * 2, wantedBase, valueToUse, left, mid);
    
    else
        diff = Set(currentNode * 2 + 1, wantedBase, valueToUse, mid + 1, right);
    
    total[currentNode] += diff;
    
    return diff;
}

int Get(int currentNode, const int wantedLeft, const int wantedRight, int currentLeft, int currentRight)
{
    if (currentLeft == currentRight)
        return base[currentLeft];
    
    // Completely inside
    if (currentLeft >= wantedLeft && currentRight <= wantedRight)
        return total[currentNode];
    
    // Partially inside
    int total = 0;
    int mid = (currentLeft + currentRight) / 2;
    
    if (currentLeft <= wantedRight && mid >= wantedLeft)
        total += Get(currentNode * 2, wantedLeft, wantedRight, currentLeft, mid);
    
    if (mid + 1 <= wantedRight && currentRight >= wantedLeft)
        total += Get(currentNode * 2 + 1, wantedLeft, wantedRight, mid + 1, currentRight);
    
    return total;
}

int main()
{
    int N;
    int T = 1;
    string sep = "";
    
    while (cin >> N, N)
    {
        for (int i = 1; i <= N; ++i)
            cin >> base[i];
        
        cout << sep << "Case " << T++ << ":\n";
        sep = "\n";
        Generate(1, 1, N);
        
        string command;
        while (cin >> command, command != "END")
        {
            int first, second;
            cin >> first >> second;
            
            if (command == "S")
                Set(1, first, second, 1, N);
            
            else
                cout << Get(1, first, second, 1, N) << '\n';
        }
    }
}