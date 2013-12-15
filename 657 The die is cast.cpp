#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define pos pair<int, int> 

void FillDot(int x, int y, int h, int w, const vector<string> &map, vector<vector<bool> > &checked, stack<pos>& s)
{    
    for (int xc = x - 1; xc < x + 2; ++xc)
    {
        for (int yc = y - 1; yc < y + 2; ++yc)
        {
            if (xc >= 0 && xc < h && yc >= 0 && yc < w && xc - x != yc - y && xc - x != y - yc 
                && !checked[xc][yc] && map[xc][yc] != '.')
            {
                checked[xc][yc] = true;
                
                if (map[xc][yc] == '*')                    
                    s.push(make_pair(xc, yc));
                
                else
                    FillDot(xc, yc, h, w, map, checked, s);
                
            }
        }
    }
}

int main()
{   
    int w, h;
    cin >> w >> h;
    
    int caseNum(1);
    while (w)
    {
        // [x][y] x < h, y < w
        vector<string> map(h);
        
        for (int i = 0; i < h; ++i)
            cin >> map[i];
            
        vector<vector<bool> > checked(h, vector<bool>(w, false));
        
        vector<int> numberOfEachOccurance(7, 0);
        
        for (int x = 0; x < h; ++x)
        {
            for (int y = 0; y < w; ++y)
            {
                if (!checked[x][y] && map[x][y] != '.')
                {
                    int numberOfDots(0);
                    stack<pos> s;
                    
                    checked[x][y] = true;
                    
                    if (map[x][y] == '*')
                        s.push(make_pair(x, y));
                    
                    else
                    {
                        ++numberOfDots;
                        FillDot(x, y, h, w, map, checked, s);
                    }
                    
                    while (!s.empty())
                    {
                        
                        pos temp = s.top();
                        s.pop();
                        
                        for (int xc = temp.first - 1; xc < temp.first + 2; ++xc)
                        {
                            for (int yc = temp.second - 1; yc < temp.second + 2; ++yc)
                            {
                                if (xc >= 0 && xc < h && yc >= 0 && yc < w && xc - temp.first != yc - temp.second && xc - temp.first != temp.second - yc 
                                    && !checked[xc][yc] && map[xc][yc] != '.')
                                {
                                    checked[xc][yc] = true;
                
                                    if (map[xc][yc] == '*')                    
                                        s.push(make_pair(xc, yc));
                                    
                                    else
                                    {
                                        ++numberOfDots;
                                        FillDot(xc, yc, h, w, map, checked, s);
                                    }
                                       
                                }
                            }
                        }
                    }
                    
                    ++numberOfEachOccurance[numberOfDots];
                    
                }
            }
        }
        
        cout << "Throw " << caseNum << '\n';
        string seperator = "";
        for (int i = 1; i < 7; ++i)
            for (int z = 0; z < numberOfEachOccurance[i]; ++z)
            {
                cout << seperator << i;
                seperator = " ";
            }

        cout << "\n\n";
             
        cin >> w >> h;
        ++caseNum;
    }
    
}