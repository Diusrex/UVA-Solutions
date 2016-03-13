#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

// WARNING: IT REQUIRES A NEWLINE AFTER EACH INPUT

using namespace std;

const int NUM_DISTINCT_NOTES_IN_SCALE = 7;

struct Scale
{
    Scale()
    {
        
    }
    
    Scale(const string& n0, const string& n1, const string& n2, const string& n3,
        const string& n4, const string& n5, const string& n6)
    {
        notes[0] = n0;
        notes[1] = n1;
        notes[2] = n2;
        notes[3] = n3;
        notes[4] = n4;
        notes[5] = n5;
        notes[6] = n6;
    }
    
    string notes[NUM_DISTINCT_NOTES_IN_SCALE];
};

map<string, Scale> scales;

void SetUpScales()
{
    scales["C"] = Scale("C", "D", "E", "F", "G", "A", "B");
    scales["Db"] = Scale("Db", "Eb", "F", "Gb", "Ab", "Bb", "C");
    scales["D"] = Scale("D", "E", "F#", "G", "A", "B", "C#");
    scales["Eb"] = Scale("Eb", "F", "G", "Ab", "Bb", "C", "D");
    scales["E"] = Scale("E", "F#", "G#", "A", "B", "C#", "D#");
    scales["F"] = Scale("F", "G", "A", "Bb", "C", "D", "E");
    scales["Gb"] = Scale("Gb", "Ab", "Bb", "Cb", "Db", "Eb", "F");
    scales["G"] = Scale("G", "A", "B", "C", "D", "E", "F#");
    scales["Ab"] = Scale("Ab", "Bb", "C", "Db", "Eb", "F", "G");
    scales["A"] = Scale("A", "B", "C#", "D", "E", "F#", "G#");
    scales["Bb"] = Scale("Bb", "C", "D", "Eb", "F", "G", "A");
    scales["B"] = Scale("B", "C#", "D#", "E", "F#", "G#", "A#");
}



int GetChange(const string& change)
{
    switch(change[2])
    {
    case 'C': // Second
        return 1;
    case 'I': // Third
        return 2;
    case 'U': // Fourth
        return 3;
    case 'F': // Fifth
        return 4;
    case 'X': // Sixth
        return 5;
    case 'V': // Seventh
        return 6;
    case 'T': // Octive
        return 0;
    }
}

vector<string> GetQueries() 
{
    string line;
    getline(cin, line);
    
    stringstream ss(line);
    string item;
    
    vector<string> elems;
    while (getline(ss, item, ';'))
        elems.push_back(item);
    
    return elems;
}

int main()
{
    SetUpScales();
    
    string key;
    while (cin >> key)
    {
        cin.ignore();
        cout << "Key of " << key << '\n';
        
        vector<string> queries = GetQueries();
        for (int i = 0; i < queries.size(); ++i)
        {
            string query = queries[i], start, direction, changeStr;
            stringstream ss(query);
            ss >> start >> direction >> changeStr;
            
            const Scale & scale = scales[key];
            int startPos = -1;
            for (int i = 0; i < NUM_DISTINCT_NOTES_IN_SCALE; ++i)
            {
                if (scale.notes[i] == start)
                    startPos = i;
            }

            cout << start << ": ";
            if (startPos != -1)
            {
                int change = GetChange(changeStr);
                if (direction[0] == 'D')
                    change = NUM_DISTINCT_NOTES_IN_SCALE - change;
                int newIndex = (startPos + change) % NUM_DISTINCT_NOTES_IN_SCALE;
                cout << direction << ' ' << changeStr << " > " << scale.notes[newIndex] << '\n';
                
            }
            else
            {
                cout << "invalid note for this key\n";
            }
        }
        cout << '\n';
    }
}