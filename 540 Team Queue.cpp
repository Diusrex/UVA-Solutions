#include <iostream>
#include <queue>

using namespace std;

int teamBelongTo[1000001];
queue<int> teamQueue[1001];
int main()
{
    int T = 1;
    int numTeams;
    while (cin >> numTeams, numTeams)
    {
        for (int t = 0; t < numTeams; ++t)
        {
            while (!teamQueue[t].empty())
                teamQueue[t].pop();
            int numElem;
            cin >> numElem;
            while (numElem--)
            {
                int elem;
                cin >> elem;
                teamBelongTo[elem] = t;
            }
        }
        
        queue<int> combinedQueue;
        
        cout << "Scenario #" << T++ << '\n';
        string command;
        while (cin >> command, command[0] != 'S')
        {
            if (command[0] == 'E')
            {
                int num;
                cin >> num;
                int team = teamBelongTo[num];
                if (teamQueue[team].empty())
                {
                    combinedQueue.push(team);
                }
                
                teamQueue[team].push(num);
            }
            else
            {
                int team = combinedQueue.front();
                cout << teamQueue[team].front() << '\n';
                teamQueue[team].pop();
                if (teamQueue[team].empty())
                    combinedQueue.pop();
            }
        }
        cout << '\n';
    }
}