#include <iostream>
#include <set>

using namespace std;

// Could just iterate through both, since sets are automatically sorted
int CountIn(const set<int> &smaller, const set<int> &larger)
{
    int count = 0;
    for (set<int>::iterator iter = smaller.begin(); iter != smaller.end(); ++iter)
        if (larger.find(*iter) != larger.end())
            ++count;
    return count;
}

int main()
{
    int N, M;
    while (cin >> N >> M, N)
    {
        set<int> first, second;
        while (N--)
        {
            int num;
            cin >> num;
            first.insert(num);
        }
        while (M--)
        {
            int num;
            cin >> num;
            second.insert(num);
        }
        
        if (first.size() < second.size())
            cout << CountIn(first, second) << '\n';
        else
            cout << CountIn(second, first) << '\n';
    }
}