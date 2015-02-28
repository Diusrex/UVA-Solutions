#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int numRooms, catStart, mouseStart;

vector<vector<int> > catDoorTo;
vector<vector<int> > mouseDoorTo;


vector<bool> catChecked; // If is false after search, then is not reachable
vector<bool> mouseChecked; // If is false after search, then is not reachable

void CatWalk(int pos)
{
    catChecked[pos] = true;
    
    for (int i = 0; i < catDoorTo[pos].size(); ++i)
    {
        if (!catChecked[catDoorTo[pos][i]])
            CatWalk(catDoorTo[pos][i]);
    }
}

bool CanFindPathHome(int pos)
{
    mouseChecked[pos] = true;
    if (catChecked[pos])
        return false;
    
    if (pos == mouseStart)
        return true;
    
    bool canMakeIt = false;
    for (int i = 0; i < mouseDoorTo[pos].size(); ++i)
    {
        if (!mouseChecked[mouseDoorTo[pos][i]])
            canMakeIt |= CanFindPathHome(mouseDoorTo[pos][i]);
    }
    
    return canMakeIt;
}

int main()
{
    int T;
    cin >> T;
    string sep = "", line;
    
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        cin >> numRooms >> catStart >> mouseStart;
        ++numRooms;
        int from, to;
        
        catDoorTo.assign(numRooms, vector<int>());
        while (cin >> from >> to, from != -1)
        {
            catDoorTo[from].push_back(to);
        }
        
        cin.ignore();
        
        mouseDoorTo.assign(numRooms, vector<int>());
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);
            ss >> from >> to;
            
            mouseDoorTo[from].push_back(to);
        }
        
        catChecked.assign(numRooms, false);
        mouseChecked.assign(numRooms, false);
        CatWalk(catStart);
        
        bool possible = false;
        for (int i = 0; i < mouseDoorTo[mouseStart].size(); ++i)
        {
            if (!mouseChecked[mouseDoorTo[mouseStart][i]])
                possible |= CanFindPathHome(mouseDoorTo[mouseStart][i]);
        }
        // Very important because if there are no valid paths, it will not be set otherwise
        mouseChecked[mouseStart] = true;
        
        bool overlap = false;
        for (int i = 0; i < numRooms; ++i)
            if (mouseChecked[i] && catChecked[i])
                overlap = true;
            
        cout << (overlap ? 'Y' : 'N') << ' ' << (possible ? 'Y' : 'N') << '\n';
    }
}