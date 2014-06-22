#include <cstdio>
#include <vector>

using namespace std;

bool find(vector<vector<int> >& number, int wanted)
{
    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            if (number[y][x] == wanted)
            {
                number[y][x] = -1;
                return true;
            }
        }
    }
    
    return false;
}

bool won(const vector<vector<int> >& number)
{
    if (number[0][0] == number[1][1] && number[3][3] == number[4][4])
        return true;
    
    if (number[4][0] == number[3][1] && number[0][4] == number[1][3])
        return true;
        
    for (int i = 0; i < 5; ++i)
    {
        if (number[i][0] == number[i][1] && number[i][2] == number[i][3] && number[i][4] == -1)
            return true;
            
        if (number[0][i] == number[1][i] && number[2][i] == number[3][i] && number[4][i] == -1)
            return true;
    }
    
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    
    while (T--)
    {
        vector<vector<int> > numbers(5, vector<int>(5));
        
        
        for (int y = 0; y < 5; ++y)
        {
            for (int x = 0; x < 5; ++x)
            {
                if (x != 2 || y != 2)
                    scanf("%d", &numbers[y][x]);
            }
        }
        
        numbers[2][2] = -1;
        
        int temp;
        int turn = 1, numHit = 0, winTurn = -1;
        
        for (; numHit < 3; ++turn)
        {
            scanf("%d", &temp);
            if (find(numbers, temp))
                ++numHit;
        }
        
        for (; turn <= 75; ++turn)
        {
            scanf("%d", &temp);
            
            if (winTurn == -1 && find(numbers, temp)
                && won(numbers))
                winTurn = turn;
        }
        
        printf("BINGO after %d numbers announced\n", winTurn);
    }
}