#include <vector>
#include <iostream>

using namespace std;

void handleStraight(const vector<string>& board, vector<vector<bool> >& attacked, int x, int y)
{
    for (int xc = -1; xc + x >= 0 && board[y][xc + x] == '.'; --xc)
        attacked[y][xc + x] = true;
    
    for (int xc = 1; xc + x  < 8 && board[y][xc + x] == '.'; ++xc)
        attacked[y][xc + x] = true;
    
    for (int yc = -1; yc + y  >= 0 && board[y + yc][x] == '.'; --yc)
        attacked[y + yc][x] = true;
    
    for (int yc = 1; yc + y  < 8 && board[y + yc][x] == '.'; ++yc)
        attacked[y + yc][x] = true;

}

void handleDiagonal(const vector<string>& board, vector<vector<bool> >& attacked, int x, int y)
{
    bool upLeft(true), upRight(true), downLeft(true), downRight(true);
    
    for (int c(1); upLeft || upRight || downLeft || downRight; ++c)
    {
        if (upLeft)
        {
            if (x - c >= 0 && y - c >= 0)
            {                
               attacked[y - c][x - c] = true;
                
                if (board[y - c][x - c] != '.')
                    upLeft = false;
            }
            else
                upLeft = false;
        }
        
        if (upRight)
        {
            if (x + c < 8 && y - c >= 0)
            {
                attacked[y - c][x + c] = true;
                
                if (board[y - c][x + c] != '.')
                    upRight = false;
            }
            else
                upRight = false;
        }
        
        if (downLeft)
        {
            if (x - c >= 0 && y + c < 8)
            {
                attacked[y + c][x - c] = true;
                
                if (board[y + c][x - c] != '.')
                    downLeft = false;
            }
            
            else
                downLeft = false;
        }
        
        if (downRight)
        {
            if (x + c < 8 && y + c < 8)
            {
                attacked[y + c][x + c] = true;
                
                if (board[y + c][x + c] != '.')
                    downRight = false;
            }
            else
                downRight = false;
        }
    }
}


void handleKnight(const vector<string>& board, vector<vector<bool> >& attacked, int x, int y)
{
    if (x - 2 >= 0)
    {
        if (y - 1 >= 0)
            attacked[y - 1][x - 2] = true;
        
        if (y + 1 < 8)
            attacked[y + 1][x - 2] = true;
    }
    
    if (x + 2 < 8)
    {
        if (y - 1 >= 0)
            attacked[y - 1][x + 2] = true;
            
        if (y + 1 < 8)
            attacked[y + 1][x + 2] = true;
    }
    
    if (y - 2 >= 0)
    {
        if (x - 1 >= 0)
            attacked[y - 2][x - 1] = true;
        
        if (x + 1 < 8)
            attacked[y - 2][x + 1] = true;
    }
    
    if (y + 2 < 8)
    {
        if (x - 1 >= 0)
            attacked[y + 2][x - 1] = true;
            
        if (x + 1 < 8)
            attacked[y + 2][x + 1] = true;
    }
}

void handlePawn(const vector<string>& board, vector<vector<bool> >& attacked, int x, int y, int yChange)
{
    if (y + yChange < 8 && y + yChange >= 0)
    {
        if (x - 1 >= 0)
            attacked[y + yChange][x - 1] = true;
        
        if (x + 1 < 8)
            attacked[y + yChange][x + 1] = true;
    }
}

void handleKing(const vector<string>& board, vector<vector<bool> >& attacked, int x, int y)
{
    if (x - 1 >= 0)
    {
        attacked[y][x - 1] = true;
        if (y - 1 >= 0)
            attacked[y - 1][x - 1] = attacked[y - 1][x] = true;
        
        if (y + 1 < 8)
            attacked[y + 1][x - 1] = attacked[y + 1][x] = true;
    }
    
    if (x + 1 < 8)
    {
        attacked[y][x + 1] = true;
        if (y - 1 >= 0)
            attacked[y - 1][x + 1] = attacked[y - 1][x] = true;
        
        if (y + 1 < 8)
            attacked[y + 1][x + 1] = attacked[y + 1][x] = true;
    }
}

int main()
{
    string input;
    
    while (cin >> input)
    {
        vector<string> board(8, "........");
        vector<vector<bool> > attacked(8, vector<bool>(8, false));
        
        int x(0), y(0);
        
        for (string::const_iterator letter = input.begin(); letter != input.end(); ++letter, ++x)
        {
            if (*letter >= '1' && *letter <= '8')
                x += (*letter - '1');
            
            else if (*letter == '/')
            {
                x = -1;
                ++y;
            }
            
            else 
            {
                attacked[y][x] = true;
                if (*letter != 'P')
                    board[y][x] = tolower(*letter);
                else
                    board[y][x] = *letter;
            }
        }
        
        for (int y = 0; y < 8; ++y)
            for (int x = 0; x < 8; ++x)
            {
                if (board[y][x] == '.')
                    continue;
                    
                if (board[y][x] == 'p')
                    handlePawn(board, attacked, x, y, 1);
                else if (board[y][x] == 'P')
                    handlePawn(board, attacked, x, y, -1);
                else if (board[y][x] == 'n')
                    handleKnight(board, attacked, x, y);
                else if (board[y][x] == 'b')
                    handleDiagonal(board, attacked, x, y);
                else if (board[y][x] == 'r')
                    handleStraight(board, attacked, x, y);
                else if (board[y][x] == 'q')
                {
                    handleDiagonal(board, attacked, x, y);
                    handleStraight(board, attacked, x, y);
                }
                else
                    handleKing(board, attacked, x, y);

            }
        
        int count(0);

        for (int y = 0; y < 8; ++y)
        {
            for (int x = 0; x < 8; ++x)
                if (!attacked[y][x])
                    ++count;
        }
        cout << count << '\n';
    }
}