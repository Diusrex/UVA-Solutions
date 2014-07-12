#include <iostream>
#include <string>

using namespace std;

int main()
{
    int conversion[128];
    conversion['='] = '-'; conversion['-'] = '0'; conversion['0'] = '9'; conversion['9'] = '8'; conversion['8'] = '7';
    conversion['7'] = '6'; conversion['6'] = '5'; conversion['5'] = '4'; conversion['4'] = '3'; conversion['3'] = '2';
    conversion['2'] = '1'; conversion['1'] = '`';
    
    conversion['\\'] = ']'; conversion[']'] = '['; conversion['['] = 'P'; conversion['P'] = 'O'; conversion['O'] = 'I'; 
    conversion['I'] = 'U'; conversion['U'] = 'Y'; conversion['Y'] = 'T'; conversion['T'] = 'R'; conversion['R'] = 'E';
    conversion['E'] = 'W'; conversion['W'] = 'Q';
    
    conversion['\''] = ';'; conversion[';'] = 'L'; conversion['L'] = 'K'; conversion['K'] = 'J'; conversion['J'] = 'H';
    conversion['H'] = 'G'; conversion['G'] = 'F'; conversion['F'] = 'D'; conversion['D'] = 'S'; conversion['S'] = 'A';
    
    conversion['/'] = '.'; conversion['.'] = ','; conversion[','] = 'M'; conversion['M'] = 'N'; conversion['N'] = 'B';
    conversion['B'] = 'V'; conversion['V'] = 'C'; conversion['C'] = 'X'; conversion['X'] = 'Z';
    
    conversion[' '] = ' '; 
    
    string line;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.size(); ++i)
            line[i] = conversion[line[i]];
        cout << line << '\n';
    }
}