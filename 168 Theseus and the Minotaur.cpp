#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> connectedTo[27];
bool lit[27];

void Solve(int from, int mino, int everyPlace)
{
    int count = 0;
    while (1)
    {
        int next = -1;
        for (int i : connectedTo[mino])
        {
            if (!lit[i] && from != i)
            {
                next = i;
                break;
            }
        }
        
        if (next == -1)
        {
            cout << "/" << (char)(mino + 'A') << '\n';
            return;
        }
        
        ++count;
        from = mino;
        mino = next;
        
        if (count == everyPlace)
        {
            cout << (char)(from + 'A') << ' ';
            lit[from] = true;
            count = 0;
        }
        
        
    }
}

int main()
{
    string line;
    
    while (getline(cin, line), line != "#")
    {
        for (int i = 0; i < 26; ++i)
        {
            lit[i] = false;
            connectedTo[i].clear();
        }
        
        int current = line[0] - 'A';
        int position = 2;
        
        for (; line[position] != '.'; ++position)
        {
            if (line[position] == ';')
            {
                ++position;
                current = line[position] - 'A';
                ++position;
            }
            else
            {
                connectedTo[current].push_back(line[position] - 'A');
            }
        }
        
        position += 2;
        int mino = line[position] - 'A'; position += 2;
        int from = line[position] - 'A'; position += 2;
        
        int everyPlace = atoi(line.substr(position).c_str());
        
        Solve(from, mino, everyPlace);
    }
}