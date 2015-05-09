#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string id;
    
    while (cin >> id, id != "#")
    {
        if (next_permutation(id.begin(), id.end()))
            cout << id << '\n';
        else
            cout << "No Successor\n";
    }
}