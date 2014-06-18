#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

char players[] = {'W', 'B'};

const int size = 8;

#define InArea(x, y) (x >= 0 && x < size && y >= 0 && y < size)

void PrintOutCount(const vector<string>& board)
{
    int b = 0, w = 0;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (board[y][x] == 'B')
                ++b;
            else if (board[y][x] == 'W')
                ++w;
        }
    }

    cout << "Black - " << std::right << std::setw(2) << b << " White - " << std::right << std::setw(2) << w << '\n';
}

bool CheckDirectionSub(const vector<string>& board, int x, int y, const int& xChange, const int& yChange, const int currentPlayer);

bool CheckDirection(const vector<string>& board, int x, int y, const int & xChange, const int & yChange, const int currentPlayer)
{
    if (xChange == 0 && yChange == 0)
        return false;

    if (board[y][x] != '-')
        return false;

    x += xChange;
    y += yChange;
    
    if (!InArea(x, y) || board[y][x] == players[currentPlayer])
        return false;
    return CheckDirectionSub(board, x, y, xChange, yChange, currentPlayer);
}

bool CheckDirectionSub(const vector<string>& board, int x, int y, const int& xChange, const int& yChange, const int currentPlayer)
{
    if (!InArea(x, y))
        return false;

    if (board[y][x] == players[currentPlayer])
        return true;
    else if (board[y][x] == '-')
        return false;

    return CheckDirectionSub(board, x + xChange, y + yChange, xChange, yChange, currentPlayer);
}

struct Position
{
    Position(int x, int y)
    :x(x), y(y) { }

    int x, y;
};

vector<Position> GetValidSpots(const vector<string>& board, const int currentPlayer)
{
    vector<Position> allPositions;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            bool valid = false;

            for (int yChange = -1; yChange < 2 && !valid; ++yChange)
            {
                for (int xChange = -1; xChange < 2; ++xChange)
                {
                    if (CheckDirection(board, x, y, xChange, yChange, currentPlayer))
                    {
                        valid = true;
                        break;
                    } 
                }
            }

            if (valid)
            {
                allPositions.push_back(Position(x + 1, y + 1));                
            }
        }
    }

    return allPositions;
}

void ApplyInDirection(vector<string> &board, int x, int y, int xChange, int yChange, char icon)
{
    while (board[y][x] != icon)
    {
        board[y][x] = icon;
        x += xChange;
        y += yChange;
    }
}

void ApplyMove(vector<string>& board, const int currentPlayer)
{
    char temp;
    cin >> temp;
    int y = temp - '1';
    cin >> temp;
    int x = temp - '1';

    for (int yChange = -1; yChange < 2; ++yChange)
    {
        for (int xChange = -1; xChange < 2; ++xChange)
        {
            if (CheckDirection(board, x, y, xChange, yChange, currentPlayer))
            {
                ApplyInDirection(board, x + xChange, y + yChange, xChange, yChange, players[currentPlayer]);
            }
        }

    }
    board[y][x] = players[currentPlayer];
}


int main()
{
    int T;
    cin >> T;

    // board is [y][x]
    vector<string> board(size);
    string sep = "";

    while (T--)
    {
        cout << sep;
        sep = "\n";
        for (int i = 0; i < size; ++i)
            cin >> board[i];


        int currentPlayer;
        char character;
        cin >> character;

        if (character == 'W') currentPlayer = 0;
        else currentPlayer = 1;

        vector<Position> spotsMayPlace = GetValidSpots(board, currentPlayer);

        while (cin >> character, character != 'Q')
        {
            if (character == 'L')
            {
                if (spotsMayPlace.size() == 0)
                    cout << "No legal move.\n";
                else
                {
                    cout << '(' << spotsMayPlace[0].y << ',' << spotsMayPlace[0].x << ')';
                    for (int i = 1; i < spotsMayPlace.size(); ++i)
                        cout << " (" << spotsMayPlace[i].y << ',' << spotsMayPlace[i].x << ')';
                    cout << '\n';
                }
            }

            else if (spotsMayPlace.size() == 0)
            {
                ApplyMove(board, 1 - currentPlayer);   
                spotsMayPlace = GetValidSpots(board, currentPlayer);
                PrintOutCount(board);
            }
            else
            {
                ApplyMove(board, currentPlayer);
                currentPlayer = 1 - currentPlayer;
                spotsMayPlace = GetValidSpots(board, currentPlayer);
                PrintOutCount(board);
            } 
        }


        for (int i = 0; i < size; ++i)
            cout << board[i] << '\n';
    }
}
