#include <iostream>
#include <algorithm>

using namespace std;

struct Job
{
    int days, fine, originalPos;
    
    bool operator<(const Job &other) const
    {
        if (days * other.fine != other.days * fine)
            return days * other.fine < other.days * fine;
        return originalPos < other.originalPos;
    }
};

Job allJobs[1005];

int main()
{
    int T;
    cin >> T;
    
    string sep = "";
    while (T--)
    {
        cout << sep;
        sep = "\n";
        
        int n;
        cin >> n;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> allJobs[i].days >> allJobs[i].fine;
            allJobs[i].originalPos = i + 1;
        }
        
        sort(allJobs, allJobs + n);
        
        cout << allJobs[0].originalPos;
        for (int i = 1; i < n; ++i)
            cout << ' ' << allJobs[i].originalPos;
        cout << '\n';
    }
}