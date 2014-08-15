#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM_NOTES_IN_CHORD = 3;
const int NUM_DIFF_NOTES = 12;

void SetUpNoteToPosAndToNote(map<string, int>& noteToPos, vector<string>& toNote)
{
    toNote.resize(NUM_DIFF_NOTES);
    noteToPos["A"] = 0; toNote[0] = "A";
    noteToPos["A#"] = noteToPos["Bb"] = 1; toNote[1] = "A#";
    noteToPos["B"] = 2; toNote[2] = "B";
    noteToPos["C"] = 3; toNote[3] = "C";
    noteToPos["C#"] = noteToPos["Db"] = 4; toNote[4] = "C#";
    noteToPos["D"] = 5; toNote[5] = "D";
    noteToPos["D#"] = noteToPos["Eb"] = 6; toNote[6] = "D#";
    noteToPos["E"] = 7; toNote[7] = "E";
    noteToPos["F"] = 8; toNote[8] = "F";
    noteToPos["F#"] = noteToPos["Gb"] = 9; toNote[9] = "F#";
    noteToPos["G"] = 10; toNote[10] = "G";
    noteToPos["G#"] = noteToPos["Ab"] = 11; toNote[11] = "G#";
}

// Will return which note value is the starting point, or -1 if no starting point
int MajorChord(const vector<int>& numbers)
{
    for (int start = 0; start < NUM_NOTES_IN_CHORD; ++start)
    {
        if ((numbers[start] + 4) % NUM_DIFF_NOTES == numbers[(start + 1) % NUM_NOTES_IN_CHORD]
            && (numbers[start] + 7) % NUM_DIFF_NOTES == numbers[(start + 2) % NUM_NOTES_IN_CHORD])
            return numbers[start];
    }

    return -1;
}

// Will return which note value is the starting point, or -1 if no starting point
int MinorChord(const vector<int>& numbers)
{
    for (int start = 0; start < NUM_NOTES_IN_CHORD; ++start)
    {
        if ((numbers[start] + 3) % NUM_DIFF_NOTES == numbers[(start + 1) % NUM_NOTES_IN_CHORD]
            && (numbers[start] + 7) % NUM_DIFF_NOTES == numbers[(start + 2) % NUM_NOTES_IN_CHORD])
            return numbers[start];
    }

    return -1;
}

int main()
{
    map<string, int> noteToPos;
    vector<string> toNote;
    SetUpNoteToPosAndToNote(noteToPos, toNote);
    
    string first, second, third;
    
    vector<int> numbers(3);
    while (cin >> first >> second >> third)
    {
        cout << first << ' ' << second << ' ' << third << " is ";
        first[0] = toupper(first[0]); numbers[0] = noteToPos[first];
        second[0] = toupper(second[0]); numbers[1] = noteToPos[second];
        third[0] = toupper(third[0]); numbers[2] = noteToPos[third];
        
        sort(numbers.begin(), numbers.end());
        
        int pos;
        if ((pos = MajorChord(numbers)) != -1) {
            cout << "a " << toNote[pos] << " Major chord.\n";
        } else if ((pos = MinorChord(numbers)) != -1) {
            cout << "a " << toNote[pos] << " Minor chord.\n";
        } else {
            cout << "unrecognized.\n";
        }
    }
    
}