#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

struct Node
{    
    long long num;
    string position;
    
    bool operator<(const Node &other) const
    {
        // Print out inital first
        if (position.size() != other.position.size())
            return position.size() < other.position.size();
        
        return position < other.position;
    }
};

bool ContainsAllParents(const set<string> &allPositions)
{
    for (set<string>::iterator iter = allPositions.begin(); 
        iter != allPositions.end(); ++iter)
    {
        if (*iter != "")
        {
            string wantedString = iter->substr(0, iter->size()-1);
            if (allPositions.find(wantedString) == allPositions.end())
                return false;
        }
    }
    
    return true;
}

Node nodes[260];

int main()
{
    set<string> allPositions;
    char firstBracket, comma;
    
    while (cin >> firstBracket >> nodes[0].num >> comma >> nodes[0].position)
    {
        allPositions.clear();
        
        // Remove the bracket
        nodes[0].position = nodes[0].position.substr(0, nodes[0].position.size()-1);
        allPositions.insert(nodes[0].position);
        
        int pos = 1;
        
        bool valid = true;
        
        while (cin >> firstBracket, cin.peek() != ')')
        {
            cin >> nodes[pos].num >> comma >> nodes[pos].position;
            
            // Remove the bracket
            nodes[pos].position = 
                nodes[pos].position.substr(0, nodes[pos].position.size()-1);
            
            if (allPositions.find(nodes[pos].position) != allPositions.end())
                valid = false;
            
            allPositions.insert(nodes[pos].position);
            
            ++pos;
        }
        
        // Remove the ) at the end
        cin.ignore();
        
        if (valid && ContainsAllParents(allPositions))
        {
            sort(nodes, nodes + pos);
        
            cout << nodes[0].num;
            for (int i = 1; i < pos; ++i)
                cout << ' ' << nodes[i].num;
            cout << '\n';
        }
        
        else
        {
            cout << "not complete\n";
        }
    }
}