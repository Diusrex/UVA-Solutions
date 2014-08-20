#include <string>
#include <iostream>
#include <map>

using namespace std;

int ToHex(const char & character)
{
    if (character >= '0' && character <= '9')
        return character - '0';
    else if (character == 'A')
        return 10;
    else if (character == 'B')
        return 11;
    else if (character == 'C')
        return 12;
    else if (character == 'D')
        return 13;
    else if (character == 'E')
        return 14;
    else
        return 15;
}

struct Input
{
    Input()
    : line("")
    {
        lineIter = line.end();
    }
    
    // Will return 'q' when done
    char GetInput()
    {
        // Checks if has loaded line before
        if (line.size())
            ++lineIter;
            
        if (lineIter == line.end())
        {
            bool endOfInput = !(cin >> line);
            if (endOfInput)
                return 'q';

            lineIter = line.begin();
        }
        
        return *lineIter;
    }
    
    int GetHexAsInt()
    {
        char temp = GetInput();
        return ToHex(temp);
    }
    
    string line;
    string::const_iterator lineIter;
} input;

// reg = Register
// add = Address
// num = number

map<char, string> codeToInstructionName;

void SetUpCodeToInstruction()
{
    codeToInstructionName['0'] = "ADD";
    codeToInstructionName['1'] = "SUB";
    codeToInstructionName['2'] = "MUL";
    codeToInstructionName['3'] = "DIV";
    codeToInstructionName['4'] = "MOV";
    codeToInstructionName['5'] = "BREQ";
    codeToInstructionName['6'] = "BRLE";
    codeToInstructionName['7'] = "BRLS";
    codeToInstructionName['8'] = "BRGE";
    codeToInstructionName['9'] = "BRGR";
    codeToInstructionName['A'] = "BRNE";
    codeToInstructionName['B'] = "BR";
    codeToInstructionName['C'] = "AND";
    codeToInstructionName['D'] = "OR";
    codeToInstructionName['E'] = "XOR";
    codeToInstructionName['F'] = "NOT";
}



void handleOperand()
{
    int firstValue = input.GetHexAsInt();
    int variableValue = firstValue % 4; // remove first two bits
    int firstInstructionValue = firstValue / 4; // shift first two bits to start
    
    for (int i = 0; i < 3; ++i)
    {
        variableValue *= 16;
        variableValue += input.GetHexAsInt();
    }
    
    switch (firstInstructionValue)
    {
    case 0:
        cout << "R" << variableValue;
        break;
    case 1:
        cout << "$" << variableValue;
        break;
    case 2:
        cout << "PC+" << variableValue;
        break;
    case 3:
        cout << variableValue;
        break;
    }
}

void HandleInstruction(const char& instruction)
{
    cout << codeToInstructionName[instruction] << ' ';
    
    switch (instruction)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
        handleOperand();
        cout << ',';
        handleOperand();
        break;
        
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'B':
    case 'F':
        handleOperand();
        break;
        
    case 'C':
    case 'D':
    case 'E':
        handleOperand();
        cout << ',';
        handleOperand();
        cout << ',';
        handleOperand();
        break;
    }
    
    cout << '\n';
}

int main()
{
    SetUpCodeToInstruction();
    
    char instruction;
    while (instruction = input.GetInput(), instruction != 'q')
    {
        HandleInstruction(instruction);
    }
}