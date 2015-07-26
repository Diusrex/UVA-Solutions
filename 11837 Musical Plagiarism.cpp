#include <iostream>
#include <vector>
#include <map>

using namespace std;

int NUM_NOTES = 12;

void GenerateMap(map<string, int> &noteToVal)
{
    noteToVal["G#"] = noteToVal["Ab"] = 0;
    noteToVal["A"] = 1;
    noteToVal["A#"] = noteToVal["Bb"] = 2;
    noteToVal["B"] = noteToVal["Cb"] = 3;
    noteToVal["B#"] = noteToVal["C"] = 4;
    noteToVal["C#"] = noteToVal["Db"] = 5;
    noteToVal["D"] = 6;
    noteToVal["D#"] = noteToVal["Eb"] = 7;
    noteToVal["E"] = noteToVal["Fb"] = 8;
    noteToVal["E#"] = noteToVal["F"] = 9;
    noteToVal["F#"] = noteToVal["Gb"] = 10;
    noteToVal["G"] = 11;
}

void ReadIn(int number, vector<int> & differences, const map<string, int> &noteToVal)
{
    differences.resize(number - 1);
    
    int previousVal, currentVal;
    string current;
    cin >> current;
    previousVal = noteToVal.find(current)->second;
    
    for (int i = 0; i < number - 1; ++i)
    {
        cin >> current;
        currentVal = noteToVal.find(current)->second;
        differences[i] = (NUM_NOTES + currentVal - previousVal) % NUM_NOTES;
        
        previousVal = currentVal;
    }
}

void Preprocess(const vector<int> &digits, vector<int> &posOnMismatch)
{
    int i = 0, j = -1;
    posOnMismatch[0] = j;
    
    while (i < digits.size()) {
        while (j >= 0 && digits[i] != digits[j])
          j = posOnMismatch[j];

        ++i; ++j;
        posOnMismatch[i] = j;
    }
}

bool IsIn(const vector<int> &original, const vector<int> &other)
{
    vector<int> posOnMismatch(other.size() + 1);
    Preprocess(other, posOnMismatch);
    
    int origPos=0, otherPos=0;
    for (int origPos = 0; origPos < original.size(); ++origPos)
    {
        while (otherPos >= 0 && original[origPos] != other[otherPos])
            otherPos = posOnMismatch[otherPos];
        
        ++otherPos;
        if (otherPos == other.size()) {
            return true;
        }
    }
    
    return false;
}

int main()
{
    map<string, int> noteToVal;
    GenerateMap(noteToVal);
    
    int origSize, otherSize;
    vector<int> original;
    vector<int> other;
    
    
    while (cin >> origSize >> otherSize, origSize)
    {
        ReadIn(origSize, original, noteToVal);
        ReadIn(otherSize, other, noteToVal);
        
        if (IsIn(original, other))
            cout << "S\n";
        else
            cout << "N\n";
    }
}