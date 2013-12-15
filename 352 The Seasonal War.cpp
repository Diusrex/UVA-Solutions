#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Fill(int x, int y, const int size, const vector<string>& image, vector<vector<bool> >& checked)
{
    for (int xc = x - 1; xc < x + 2; ++xc)
    {
        for (int yc = y - 1; yc < y + 2; ++yc)
        {
            if (yc >= 0 && yc < size && xc >= 0 && xc < size
                && image[xc][yc] == '1' && !checked[xc][yc])
            {
                checked[xc][yc] = true;
                Fill(xc, yc, size, image, checked);
            }
        }
    }
}

int main()
{
    int d;
    
    //ifstream loadFile;
    //loadFile.open("Bumble.in");
    
    //ofstream writeFile;
    //writeFile.open("Bumble.out");
    
    int imageCount(1);
    while (cin >> d && d)
    {
        vector<string> image(d);
        
        for (int i = 0; i < d; ++i)
            cin >> image[i];
        
        vector<vector<bool> > checked(d, vector<bool> (d, false));
        
        int count(0);
        
        for (int x = 0; x < d; ++x)
        {
            for (int y = 0; y < d; ++y)
            {
                if (image[x][y] == '1' && !checked[x][y])
                {
                    ++count;
                    checked[x][y] = true;
                    Fill(x, y, d, image, checked);
                
                }
            
            }
        }
        
        cout << "Image number " << imageCount << " contains " << count << " war eagles.\n";
        
        ++imageCount;
    }

}