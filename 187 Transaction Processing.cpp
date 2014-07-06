#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

void PrintFormatted(const string& id, const string& name, const int & total)
{
    bool addNegative = (total / 100) == 0 && total < 0;
    
    int cents = abs(total % 100); 
    
    cout << id << ' ' << std::fixed << setw(30) << std::left << name << ' ';
    
    if (addNegative)
        cout << std::right << setw(7) << "-0";
        
    else
        cout << std::right << setw(7) << (total / 100);

    cout << '.' << ((cents < 10) ? "0" : "") << cents << '\n';
}

bool first = true;

void FinishTransaction(const string& transactionId, const vector<string> & order, map<string, int>& idToCost, int& totalCost, map<string, string>& accounts)
{
    if (transactionId != "" && totalCost != 0)
    {
        
        cout << "*** Transaction " << transactionId << " is out of balance ***\n";
        
        for (vector<string>::const_iterator iter = order.begin(); iter != order.end(); ++iter)
        {
        
            if (idToCost.find(*iter) != idToCost.end())
                PrintFormatted(*iter, accounts[*iter], idToCost[*iter]);
            
            
        }
        
        PrintFormatted("999", "Out of Balance", totalCost);
        
        cout << '\n';
    }
    
    idToCost.clear();
    totalCost = 0;
}

int main()
{
    map<string, string> accounts;
    
    string temp, id;
    
    vector<string> order;
    
    while (getline(cin, temp), (id = temp.substr(0, 3)) != "000")
    {
        accounts[id] = temp.erase(0, 3);
        order.push_back(id);
    }
    
    string transactionId = "", tempTransaction;
    
    
    map<string, int> idToCost;
    
    int totalCost;
    int currentCost;
    
    while (cin >> temp >> currentCost, (tempTransaction = temp.substr(0, 3)) != "000")
    {
        if (tempTransaction != transactionId)
        {
            FinishTransaction(transactionId, order, idToCost, totalCost, accounts);
            transactionId = tempTransaction;
        }
        totalCost -= currentCost;
        
        string id = temp.substr(3, 3);
        
        if (idToCost.find(id) == idToCost.end())
        {
            idToCost[id] = currentCost;
        }
        else 
        {
            idToCost[id] += currentCost;
        }
    }
    
}