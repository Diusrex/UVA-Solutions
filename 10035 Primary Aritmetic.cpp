#include <iostream>

using namespace std;

int main()
{
	unsigned long first, second;

	cin >> first >> second;

	while (first != 0 || second != 0)
	{
		int count(0);
	
		
		bool carryOver(false);

		while (first || second)
		{
			int current = first % 10 + second % 10;

			if (carryOver)
			{
				++current;
				carryOver = false;
			}

			if (current >= 10)
			{
				++count;
				carryOver = true;
			}

			first /= 10;
			second /= 10;
		}
		if (count == 0)
			cout << "No";
		else
			cout << count;

		cout << " carry operation";
		if (count > 1)
			cout << "s";

		cout << ".\n";
		cin >> first >> second;
	}
}
