#include <iostream>

using namespace std;

int main()
{
    int needed[] = {56, 51, 41, 36};
    int numOulders, T, numCards;
    
    double points;
    string currentLine, seperator("");
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        numOulders = points = 0;
        
        cin >> numCards;
        
        cin.ignore();
        
        for (int i = 0; i < numCards; ++i)
        {
            getline(cin, currentLine);
            
            if (currentLine == "twenty-one of trumps" || currentLine == "fool" || currentLine == "one of trumps")
            {
                ++numOulders;
                points += 4.5;
            }
            
            else if (currentLine.find("king") != string::npos)
                points += 4.5;
            
            
            else if (currentLine.find("queen") != string::npos)
                points += 3.5;
            
            
            else if (currentLine.find("knight") != string::npos)
                points += 2.5;
            
            
            else if (currentLine.find("jack") != string::npos)
                points += 1.5;
            
            
            else
                points += 0.5;
        }
        
        cout << seperator << "Hand #" << t << '\n';
        seperator = "\n";
        
        if (points < needed[numOulders])
            cout << "Game lost by " << needed[numOulders] - points << " point(s).\n";
         
        else
            cout << "Game won by " << points - needed[numOulders] << " point(s).\n";
    }
    
}