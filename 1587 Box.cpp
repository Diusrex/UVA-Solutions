#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

struct Pallet
{
	int l, s;

	void Set(int h, int w)
	{
		l = max(h, w);
		s = min(h, w);
	}

    bool operator==(const Pallet & other) const
    {
        return l == other.l && s == other.s;
    }
    
    bool operator!=(const Pallet &other) const
    {
        return l != other.l || s != other.s;
    }
};

bool SortComparison(const Pallet & lhs, const Pallet & rhs)
{
    if (lhs.l != rhs.l)
        return lhs.l > rhs.l;

   return lhs.s > rhs.s;
}

Pallet pallets[6];

bool IsValid()
{
	sort(pallets, pallets + 6, SortComparison);
    
    if (pallets[0] != pallets[1] || pallets[2] != pallets[3] || pallets[4] != pallets[5])
        return false;
    
    if (pallets[0].l != pallets[2].l)
        return false;

    if (pallets[2].s == pallets[4].l)
        return pallets[0].s == pallets[4].s;

    return pallets[2].s == pallets[4].s && pallets[0].s == pallets[4].l;
}

int main()
{
    int h, w;
	while (cin >> h >> w)
    {
		pallets[0].Set(h, w);

        for (int i = 1; i < 6; ++i)
        {
                cin >> h >> w;
                pallets[i].Set(h, w);
        }
        
        if (IsValid())
            cout << "POSSIBLE\n";
        else
            cout << "IMPOSSIBLE\n";
	}
}