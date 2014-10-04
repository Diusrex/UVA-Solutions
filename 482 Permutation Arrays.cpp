#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

void ReadIntLine(vector<int>& numbers)
{
    string line;
    getline(cin, line);
    
    istringstream is(line);
        
    numbers = vector<int>(istream_iterator<int>(is), istream_iterator<int>());
}

void ReadDoubleLine(vector<string>& numbers)
{
    string line;
    getline(cin, line);
    
    istringstream is(line);
        
    numbers = vector<string>(istream_iterator<string>(is), istream_iterator<string>());
}

int main()
{
    bool first = true;
    
    int T;
    cin >> T;
    cin.ignore();
    
    string blankLine;
    while (T--)
    {
        getline(cin, blankLine);
        if (!first)
            cout << "\n";
        first = false;
        
        vector<int> placeToMoveTo;
        ReadIntLine(placeToMoveTo);
        
        vector<string> permutedLine;
        ReadDoubleLine(permutedLine);
        
        vector<string> origionalLine(permutedLine.size());
        
        for (int i = 0; i < placeToMoveTo.size(); ++i)
            origionalLine[placeToMoveTo[i] - 1] = permutedLine[i];

        for (int i = 0; i < origionalLine.size(); ++i)
            cout << origionalLine[i] << '\n';
        // print output
    }
}