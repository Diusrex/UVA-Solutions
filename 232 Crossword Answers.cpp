#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int r, c;
    
    string separator = "";
    
    int T(1);
    
    while (cin >> r, r)
    {
        cin >> c;
        
        vector<string> words(r);
        
        for (int i = 0; i < r; ++i)
        {
            cin >> words[i];
        }
        
        // is [y][x]
        vector<vector<bool> > hitAcross(r, vector<bool>(c, false));
        vector<vector<bool> > hitDown(hitAcross);
        
        vector<int> acrossCount, downCount;
        vector<string> acrossOutput, downOutput;
        
        int wordCount(1);
        for (int y = 0; y < r; ++y)
        {            
            for (int x = 0; x < c; ++x)
            {
                bool increase = false;
                
                if (words[y][x] != '*' && !hitAcross[y][x])
                {
                    string current = "";
                    for (int newX = x; newX < c && words[y][newX] != '*'; ++newX)
                    {
                        hitAcross[y][newX] = true;
                        current += words[y][newX];
                    }
                    acrossOutput.push_back(current);
                    acrossCount.push_back(wordCount);
                    increase = true;
                }
                
                if (words[y][x] != '*' && !hitDown[y][x])
                {
                    string current = "";
                    for (int newY = y; newY < r && words[newY][x] != '*'; ++newY)
                    {
                        hitDown[newY][x] = true;
                        current += words[newY][x];
                    }
                    downOutput.push_back(current);
                    downCount.push_back(wordCount);
                    increase = true;
                }
                
                if (increase)
                    ++wordCount;
            }
        }
        cout << separator << "puzzle #" << T++ << ":\nAcross\n";
        separator = "\n";
        for (int i = 0; i < acrossOutput.size(); ++i)
        {
            cout << right << setw(3) << acrossCount[i] << '.' << acrossOutput[i] << '\n';
        }
        cout << "Down\n";
        for (int i = 0; i < downOutput.size(); ++i)
        {
            cout << right << setw(3) << downCount[i] << '.' << downOutput[i] << '\n';
        }
    }
}