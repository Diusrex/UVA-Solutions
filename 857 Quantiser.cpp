#include <vector>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

const int PLAY_NOTE = 1;
const int RELEASE_NOTE = 0;

struct data {
    int code, note, m, b, t;
    
    void load()
    {
        scanf("%d%d%d%d%d", &code, &note, &m, &b, &t);
        
        round();
    }
    
    void print()
    {
        printf("%d %d %d %d %d\n", code, note, m, b, t);
    }
    
    void round()
    {
        t = ((t + 30) / 60) * 60;
        
        if (t == 480) {
            t = 0;
            b++;
            if (b == 5) {
                b = 1;
                m++;
            }
        }
    }
    
    inline bool operator!= (const data& rhs)
    {
        return m != rhs.m || b != rhs.b || t != rhs.t;
    }
};

int main()
{
    int numMessage;
    
    while (scanf("%d", &numMessage), numMessage != -1)
    {
        map<int, int> currentInfoPos;
        
        // The bool is for if it is valid
        vector<pair<data, bool> > allData;
        
        int successful = 0;
        
        while (numMessage--)
        {
            data currentData;
            currentData.load();
            
            if (currentData.code == PLAY_NOTE)
            {
                currentInfoPos[currentData.note] = allData.size();
                allData.push_back(make_pair(currentData, true));
                ++successful;
            }
            
            else
            {
                int pos = currentInfoPos[currentData.note];
                
                if (currentData != allData[pos].first)
                {
                    ++successful;
                    allData[pos].second = true;
                    allData.push_back(make_pair(currentData, true));
                }
                
                else
                {
                    allData[pos].second = false;
                    --successful;
                }
            }
        }
        
        printf("%d\n", successful);
        
        for (int i = 0; i < allData.size(); ++i)
        {
            if (allData[i].second)
                allData[i].first.print();
        }
    }
    
    printf("-1\n");
}