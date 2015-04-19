#include <string>
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
const int UNKNOWN = -1;

int mem[MAX_SIZE][MAX_SIZE];
string first, second;

int MostInCommon(int posInFirst, int posInSecond)
{
    if (posInFirst == first.size() || posInSecond == second.size())
        return 0;
    
    int &val = mem[posInFirst][posInSecond];
    if (val == UNKNOWN)
    {
        if (first[posInFirst] == second[posInSecond])
            val = 1 + MostInCommon(posInFirst + 1, posInSecond + 1);
        
        else
            val =  max(MostInCommon(posInFirst + 1, posInSecond),
                       MostInCommon(posInFirst, posInSecond + 1));
    }
    
    return val;
}

int main()
{
    int t = 1;
    while (getline(cin, first), first[0] != '#')
    {
        getline(cin, second);
        for (int i = 0; i < first.size(); ++i)
        {
            for (int j = 0; j < second.size(); ++j)
            {
                mem[i][j] = UNKNOWN;
            }
        }
        cout << "Case #" << t++ << ": you can visit at most " << MostInCommon(0, 0) << " cities.\n";
    }
}