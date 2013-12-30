#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, p, bestMet, tempMet, t = 1;
    double tempPrice, bestPrice;
    string temp, best, junk, separator = "";
    
    while (scanf("%d %d", &n, &p), n)
    {
        cout << separator;
        separator = "\n";
        bestMet = bestPrice = -1;
        cin.ignore();
        
        // Remove requirement names
        
        for (int i = 0; i < n; ++i)
        
            getline(cin, junk);
        
        
        while (p--)
        {
            getline(cin, temp);
            
            scanf("%lf %d", &tempPrice, &tempMet);
            
            cin.ignore();
            
            for (int i = 0; i < tempMet; ++i)
                getline(cin, junk);
            
            
            if (tempMet > bestMet || (tempMet == bestMet && (tempPrice < bestPrice || bestPrice == -1)))
            {
                best = temp;
                bestPrice = tempPrice;
                bestMet = tempMet;
            }
        }
        
        printf("RFP #%d\n%s\n", t, best.c_str());
        
        ++t;
    }
    
    
}