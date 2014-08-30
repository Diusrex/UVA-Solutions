#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Traveller
{
    string name;
    int balance; // negative means owed money
    
    bool operator<(const Traveller & other) const { return balance < other.balance; }
};

void GetInput(int n, int t, vector<Traveller>& travellers)
{
    travellers.resize(n);
    map<string, int> nameToPos;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> travellers[i].name;
        travellers[i].balance = 0;
        nameToPos[travellers[i].name] = i;
    }
    
    string name1, name2;
    
    while (t--)
    {
        int amount;
        cin >> name1 >> name2 >> amount;
        
        int pos1 = nameToPos[name1];
        int pos2 = nameToPos[name2];
        
        travellers[pos1].balance -= amount;
        travellers[pos2].balance += amount;
    }
}



void SolveAndPrint(const int n, vector<Traveller> & travellers)
{
    sort(travellers.begin(), travellers.end());
    
    for (int firstUneven = 0, lastUneven = travellers.size() - 1; firstUneven < lastUneven; )
    {
        // Is the amount after the last has paid the first
        int amountLeft = travellers[firstUneven].balance + travellers[lastUneven].balance;
        cout << travellers[lastUneven].name << ' ' << travellers[firstUneven].name << ' ';
        
        // More owed to first than last owes
        if (amountLeft < 0)
        {
            cout << travellers[lastUneven].balance;
            --lastUneven;
            travellers[firstUneven].balance = amountLeft;
        }
        
        // Last owes more than first owed
        else if (amountLeft > 0)
        {
            cout << -travellers[firstUneven].balance;
            ++firstUneven;
            travellers[lastUneven].balance = amountLeft;
        }
        
        // Owe same amount
        else
        {
            cout << travellers[lastUneven].balance;
            ++firstUneven;
            --lastUneven;
        }
        
        cout << '\n';
    }
}



int main()
{
    int n, t;
    int T = 1;
    
    vector<Traveller> travellers;
    
    while (cin >> n >> t, n != 0)
    {
        GetInput(n, t, travellers);
        
        cout << "Case #" << T++ << '\n';
        SolveAndPrint(n, travellers);
        cout << '\n';
    }
}