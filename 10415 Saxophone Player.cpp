#include <vector>
#include <string>
#include <iostream>

using namespace std;

inline void Check(int pos, vector<bool> & previousPressed, vector<int> & counts)
{
    if (!previousPressed[pos])
        ++counts[pos];
}

void ChangeNote(const char & note, vector<bool> & previousPressed, vector<int> & counts)
{
    vector<bool> newPressed(11, false);
    switch (note)
    {
    case 'C':
        Check(3, previousPressed, counts);
        newPressed[3] = true;
        break;
        
    case 'c':
        Check(10, previousPressed, counts);
        newPressed[10] = true;
    case 'd':
        Check(9, previousPressed, counts);
        newPressed[9] = true;
    case 'e':
        Check(8, previousPressed, counts);
        newPressed[8] = true;
    case 'f':
        Check(7, previousPressed, counts);
        newPressed[7] = true;
    case 'g':
        Check(4, previousPressed, counts);
        newPressed[4] = true;
    case 'a':
        Check(3, previousPressed, counts);
        newPressed[3] = true;
    case 'b':
        Check(2, previousPressed, counts);
        newPressed[2] = true;
        break;
    
    case 'D':
        Check(9, previousPressed, counts);
        newPressed[9] = true;
    case 'E':
        Check(8, previousPressed, counts);
        newPressed[8] = true;
    case 'F':
        Check(7, previousPressed, counts);
        newPressed[7] = true;
    case 'G':
        Check(4, previousPressed, counts);
        newPressed[4] = true;
    case 'A':
        Check(3, previousPressed, counts);
        newPressed[3] = true;
    case 'B':
        Check(2, previousPressed, counts);
        newPressed[2] = true;
        Check(1, previousPressed, counts);
        newPressed[1] = true;
        break;
    }
    
    previousPressed.swap(newPressed);
}

int main()
{
    vector<int> counts(11);
    string phrase;
    
    int T;
    cin >> T;
    cin.ignore();
    
    while (T--)
    {
        for (int i = 1; i < 11; ++i)
            counts[i] = 0;
        
        getline(cin, phrase);
        
        vector<bool> previousPressed(11, false);
        
        for (int i = 0; i < phrase.size(); ++i)
            ChangeNote(phrase[i], previousPressed, counts);
        
        for (int i = 1; i < 10; ++i)
            cout << counts[i] << ' ';
            
        cout << counts[10] << '\n';
    }
}