#include <iostream>

using namespace std;

long Reverse(long x)
{
	long newX(0);
	
	while (x)
	{
		newX *= 10;
		newX += x % 10;
		x /= 10;
	}
	
	return newX;
}

int main()
{
	int numberOfCases;
	
	cin >> numberOfCases;
	
	for (int i = 0; i < numberOfCases; ++i)
	{
		long number;
		cin >> number;
		
		long reverseNumber = Reverse(number);
		
		int count(0);
		while (reverseNumber != number)
		{
			number += reverseNumber;
			reverseNumber = Reverse(number);
			++count;
		}
		cout << count << " " << number << endl;
	}
}
