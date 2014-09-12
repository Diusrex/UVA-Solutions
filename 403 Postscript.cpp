#include <vector>
#include <iostream>
#include <string>

using namespace std;

// (Ignores the space between characters)
// positionWithStars is [column + row * 5]
string positionsWithStars[] = {".***.*...*******...**...*", // A
                               "****.*...*****.*...*****.", // B
                               ".*****...**....*.....****", // C
                               "****.*...**...**...*****.", // D
                               "******....***..*....*****", // E
                               "******....***..*....*....", // F
                               ".*****....*..***...*.***.", // G
                               "*...**...*******...**...*", // H
                               "*****..*....*....*..*****", // I
                               "..***...*....*.*..*..**..", // J
                               "*...**..*.***..*..*.*...*", // K
                               "*....*....*....*....*****", // L
                               "*...***.***.*.**...**...*", // M
                               "*...***..**.*.**..***...*", // N
                               ".***.*...**...**...*.***.", // O
                               "****.*...*****.*....*....", // P
                               ".***.*...**...**..**.****", // Q
                               "****.*...*****.*..*.*...*", // R
                               ".*****.....***.....*****.", // S
                               "******.*.*..*....*...***.", // T
                               "*...**...**...**...*.***.", // U
                               "*...**...*.*.*..*.*...*..", // V
                               "*...**...**.*.***.***...*", // W
                               "*...*.*.*...*...*.*.*...*", // X
                               "*...*.*.*...*....*....*..", // Y
                               "*****...*...*...*...*****"}; // Z

string GetPhrase()
{
    string line;
    getline(cin, line);
    
    int newStart = 2, newEnd = line.find_last_of('|');
    return line.substr(newStart, newEnd - newStart);
}

int DetermineLength(const string& font, const string& phrase);
void HandlePrint(const string& font, const int & row, const int & column, const string& phrase);

const int NUM_CHARACTERS = 60;
const string blankLine(NUM_CHARACTERS, '.');
const string separatorLine(NUM_CHARACTERS, '-');

// is [row][column
vector<string> lines(NUM_CHARACTERS, blankLine);

int main()
{
    string command;
    
    while (cin >> command)
    {
        if (command == ".EOP")
        {
            for (int line = 0; line < NUM_CHARACTERS; ++line)
            {
                cout << lines[line] << '\n';
                lines[line] = blankLine;
            }
            
            cout << '\n' << separatorLine << "\n\n";
            
        }
        
        else if (command == ".P")
        {
            string font;
            int row, column;
            cin >> font >> row >> column;
            
            --row;
            --column;
            
            HandlePrint(font, row, column, GetPhrase());
        }
        
        else if (command == ".L")
        {
            string font;
            int row;
            cin >> font >> row;
            
            --row;
            
            HandlePrint(font, row, 0, GetPhrase());
        }
        
        else if (command == ".R")
        {
            string font;
            int row;
            cin >> font >> row;
            
            --row;
            
            string phrase = GetPhrase();
            int column = 60 - DetermineLength(font, phrase);
        
            HandlePrint(font, row, column, phrase);
        }
        
        else
        {
            // .C
            string font;
            int row;
            cin >> font >> row;
            
            --row;
            
            string phrase = GetPhrase();
            int phraseLength = DetermineLength(font, phrase);
            
            int column = 30 - phraseLength / 2;
            
            HandlePrint(font, row, column, phrase);
        }
    }
}

int DetermineLength(const string& font, const string& phrase)
{
    if (font == "C1")
    {
        return phrase.size();
    }
    else
    {
        return phrase.size() * 6;
    }
}

void PrintSmallFont(const int & rowStart, const int & columnStart, const string& phrase);
void PrintLargeFont(const int & rowStart, const int & columnStart, const string& phrase);

void HandlePrint(const string& font, const int & row, const int & column, const string& phrase)
{
    if (font == "C1")
        PrintSmallFont(row, column, phrase);
    else
        PrintLargeFont(row, column, phrase);
}

void PrintSmallFont(const int & rowStart, const int & columnStart, const string& phrase)
{
    int currentColumn = columnStart;
    for (string::const_iterator iter = phrase.begin(); iter != phrase.end() && currentColumn < NUM_CHARACTERS; ++iter, ++currentColumn)
    {
        if (*iter != ' ')
            lines[rowStart][currentColumn] = *iter;
    }
}


void PrintLargeFont(const int & rowStart, const int & columnStart, const string& phrase)
{
    for (int characterLine = 0, currentRowInLines = rowStart; characterLine < 5 && currentRowInLines < NUM_CHARACTERS; ++characterLine, ++currentRowInLines)
    {
        int currentColumn = columnStart;
        
        for (string::const_iterator iter = phrase.begin(); iter != phrase.end() && currentColumn < NUM_CHARACTERS; ++iter, ++currentColumn) // increase here is for the space
        {
            if (*iter == ' ')
            {
                //for (int i = 0; i < 5; ++i, ++currentColumn)
                currentColumn += 5;
                continue;
            }
            
            for (int characterColumn = 0; characterColumn < 5 && currentColumn < NUM_CHARACTERS; ++characterColumn, ++currentColumn)
            {
                if (currentColumn >= 0)
                {
                    if (positionsWithStars[*iter - 'A'][characterColumn + characterLine * 5] == '*')
                        lines[currentRowInLines][currentColumn] = '*';
                }
            }
        }
    }
}