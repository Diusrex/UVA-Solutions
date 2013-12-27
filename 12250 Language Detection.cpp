#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{   
    string current;
    
    int t = 1;
    
    cin >> current;
    while (current != "#")
    {
        printf("Case %d: ", t);
        
        if (current == "HELLO")
            printf("ENGLISH\n");
        else if (current == "HOLA")
            printf("SPANISH\n");
        else if (current == "HALLO")
            printf("GERMAN\n");
        else if (current == "BONJOUR")
            printf("FRENCH\n");
        else if (current == "CIAO")
            printf("ITALIAN\n");
        else if (current == "ZDRAVSTVUJTE")
            printf("RUSSIAN\n");
        else
            printf("UNKNOWN\n");
        ++t;
        
        cin >> current;
    }

}