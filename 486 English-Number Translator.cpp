#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    string line;
    map<string, int> convert;
    convert["zero"] = 0;
    convert["one"] = 1;
    convert["two"] = 2;
    convert["three"] = 3;
    convert["four"] = 4;
    convert["five"] = 5;
    convert["six"] = 6;
    convert["seven"] = 7;
    convert["eight"] = 8;
    convert["nine"] = 9;
    convert["ten"] = 10;
    convert["eleven"] = 11;
    convert["twelve"] = 12;
    convert["thirteen"] = 13;
    convert["fourteen"] = 14;
    convert["fifteen"] = 15;
    convert["sixteen"] = 16;
    convert["seventeen"] = 17;
    convert["eighteen"] = 18;
    convert["nineteen"] = 19;
    convert["twenty"] = 20;
    convert["thirty"] = 30;
    convert["forty"] = 40;
    convert["fifty"] = 50;
    convert["sixty"] = 60;
    convert["seventy"] = 70;
    convert["eighty"] = 80;
    convert["ninety"] = 90;
    
    
    while (getline(cin, line))
    {
        bool negative = false;
        int num = 0, total = 0;
        
        stringstream ss(line);
        string word;
        
        while (ss >> word)
        {
            if (word == "negative")
                negative = true;
            else if (word == "million")
            {
                total += num * 1000000;
                num = 0;
            }
            else if (word == "thousand")
            {
                total += num * 1000;
                num = 0;
            }
            else if (word == "hundred")
            {
                num = num * 100;
            }
            else
            {
                num += convert[word];
            }
        }
        
        total += num;
        
        if (negative)
            total = -total;
        cout << total << '\n';
    }
}