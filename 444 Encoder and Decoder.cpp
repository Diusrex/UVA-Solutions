#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool IsEncoded(string phrase)
{
    return phrase[0] >= '0' && phrase[0] <= '9';
}

int ToInt(const string & str)
{
    return atoi(str.c_str());
}

string ToString(int i)
{
    stringstream ss;
    ss << i;
    string asString;
    ss >> asString;
    return asString;
}

void DecodeAndPrint(string & phrase)
{
    reverse(phrase.begin(), phrase.end());
    
    int pos = 0;
    string output = "";
    
    while (pos + 1 <phrase.size())
    {
        int len = 2;
        if (phrase[pos] == '1')
            ++len;
            
        output += static_cast<char>(ToInt(phrase.substr(pos, len)));
        
        pos += len;
    }
    
    cout << output << '\n';
}

void EncodeAndPrint(string & line)
{
    string output;
    
    for (char c : line)
    {
        output += ToString(static_cast<int>(c));
    }
    
    reverse(output.begin(), output.end());
    cout << output << '\n';
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (IsEncoded(line))
            DecodeAndPrint(line);
        else
            EncodeAndPrint(line);
    }
}