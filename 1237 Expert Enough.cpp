#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


struct Maker
{
    string name;
    int min, max;
    
    void Read()
    {
        cin >> name >> min >> max;
    }
};

const string UNKNOWN = "UNDETERMINED";

string GetOutput(vector<Maker> & info, int valueWanted)
{
    string match = "";
    for (const Maker & m : info)
    {
        if (m.min <= valueWanted && m.max >= valueWanted)
        {
            if (match == "")
                match = m.name;
            else
                return UNKNOWN;
        }
    }
    
    if (match == "")
        return UNKNOWN;
    
    return match;
}

int main()
{
    vector<Maker> info;
    
    int T;
    cin >> T;
    
    bool first = true;
    
    while (T--)
    {
        if (!first)
            cout << '\n';
        else
            first = false;
            
        int N;
        cin >> N;
        info.resize(N);
        
        for (Maker & m : info)
            m.Read();
        
        int Q;
        cin >> Q;
        
        while (Q--)
        {
            int P;
            cin >> P;
            
            cout << GetOutput(info, P) << '\n';
        }
    }
}