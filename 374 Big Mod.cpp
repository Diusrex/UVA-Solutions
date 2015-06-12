#include <iostream>

using namespace std;

// Don't need to use long long because the mod^2 is still containable by a signed int

int myPow(int b, int p, int m)
{
	b = b % m;
	int total = 1;
	
	while (p)
	{
		if (p & 1)
			total = (total * b) % m;
		
		b = (b * b) % m;
		p >>= 1;
	}

	return total;
}


int main()
{
	int b, p, m;
	
	while (cin >> b >> p >> m)
	{
		cout << myPow(b, p, m) << '\n';
	}
}