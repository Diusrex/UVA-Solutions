#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const int NUM_NOTES = 12;

string notePosition [] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

int GetNotePos(const string& note)
{
    int pos = 0;
    
    while (notePosition[pos] != note)
        ++pos;
    
    return pos;
}

vector<vector<bool> > GenerateScalePossibilities()
{
    vector<vector<bool> > allNotesPossibleInScales(NUM_NOTES, vector<bool>(NUM_NOTES, false));

    for (int scale = 0; scale < NUM_NOTES; ++scale)
    {
        allNotesPossibleInScales[scale][scale] = 
        allNotesPossibleInScales[scale][(scale + 2) % NUM_NOTES] = 
        allNotesPossibleInScales[scale][(scale + 4) % NUM_NOTES] = 
        allNotesPossibleInScales[scale][(scale + 5) % NUM_NOTES] = 
        allNotesPossibleInScales[scale][(scale + 7) % NUM_NOTES] = 
        allNotesPossibleInScales[scale][(scale + 9) % NUM_NOTES] = 
        allNotesPossibleInScales[scale][(scale + 11) % NUM_NOTES] = true;
    }
    
    return allNotesPossibleInScales;
}

bool MeetsNotePossibilies(const vector<bool> & scale, const vector<bool>& playedNotes)
{
    for (int i = 0; i < NUM_NOTES; ++i)
    {
        if (playedNotes[i] && !scale[i])
            return false;
    }
    return true;
}

int main()
{
    vector<vector<bool> > allNotesPossibleInScales = GenerateScalePossibilities();
    
    string line, note, separator;
    
    vector<bool> playedNotes(NUM_NOTES);
    
    while (getline(cin, line), line != "END")
    {
        for (int i = 0; i < NUM_NOTES; ++i)
            playedNotes[i] = false;
            
        stringstream ss(line);
        
        while (ss >> note)
            playedNotes[GetNotePos(note)] = true;
        
        separator = "";
        
        for (int i = 0; i < NUM_NOTES; ++i)
        {
            if (MeetsNotePossibilies(allNotesPossibleInScales[i], playedNotes))
            {
                cout << separator << notePosition[i];
                separator = " ";
            }
        }
        cout << '\n';
    }
}