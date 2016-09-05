#include <iostream>
#include <sstream>
#include <map>

using namespace std;

bool IsCorrect(const string& line, map<string, int>& partyVotes)
{
    stringstream ss(line);
    string party, sep;
    int sum = 0;
    
    do
    {
        ss >> party >> sep;
        sum += partyVotes[party];
    } while (sep == "+");
    
    int against;
    ss >> against;
    against *= 10;
    if (sum == against)
        return sep.find('=') != string::npos;
    else if (sum > against)
        return sep.find('>') != string::npos;
    else // sum < against
        return sep.find('<') != string::npos;
}

int main()
{
    int P, G;
    cin >> P >> G;
    
    map<string, int> partyVotes;
    
    for (int i = 0; i < P; ++i)
    {
        string name;
        int beforeDec, afterDec;
        char dec;
        cin >> name >> beforeDec >> dec >> afterDec;
        partyVotes[name] = beforeDec * 10 + afterDec;
    }
    
    cin.ignore();
    
    for (int g = 1; g <= G; ++g)
    {
        string guess;
        getline(cin, guess);
        cout << "Guess #" << g << " was " <<
            (IsCorrect(guess, partyVotes) ? "correct" : "incorrect") << ".\n";
    }
}