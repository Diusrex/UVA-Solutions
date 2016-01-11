#include <iostream>

using namespace std;

bool connected[26][26];
bool alreadyChecked[26];

int N;

void Connect(int node)
{
    alreadyChecked[node] = true;

    for (int i = 0; i < N; ++i)
        if (connected[node][i] && !alreadyChecked[i])
            Connect(i);
}

int main()
{
    int T;
    cin >> T;

    string sep = "";

    while (T--)
    {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                connected[i][j] = false;

        {
        char temp;
        cin >> temp;
        N = temp - 'A' + 1;
        }

        string line;

        cin.ignore();
        while (getline(cin, line) && line != "")
        {
            int a = line[0] - 'A', b = line[1] - 'A';
            connected[a][b] = connected[b][a] = true;
        }

        for (int i = 0; i < N; ++i)
            alreadyChecked[i] = false;
        
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (!alreadyChecked[i])
            {
                Connect(i);
                ++count;
            }

        cout << sep << count << '\n';
        sep = "\n";
    }
}
