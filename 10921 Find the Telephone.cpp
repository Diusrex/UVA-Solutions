#include <iostream>
#include <string>

using namespace std;

char conversions[128];
void SetUpconversionss()
{
    for (int i = 0; i < 128; ++i)
        conversions[i] = i;
    
    conversions['A'] = conversions['B'] = conversions['C'] = '2';
    conversions['D'] = conversions['E'] = conversions['F'] = '3';
    conversions['G'] = conversions['H'] = conversions['I'] = '4';
    conversions['J'] = conversions['K'] = conversions['L'] = '5';
    conversions['M'] = conversions['N'] = conversions['O'] = '6';
    conversions['P'] = conversions['Q'] = conversions['R'] = conversions['S'] = '7';
    conversions['T'] = conversions['U'] = conversions['V'] = '8';
    conversions['W'] = conversions['X'] = conversions['Y'] = conversions['Z'] = '9';
}

int main()
{
    SetUpconversionss();
    
    string line;
    
    while (getline(cin, line))
    {
        for (int i = 0; i < line.size(); ++i)
            line[i] = conversions[line[i]];
        
        cout << line << '\n';
    }
}