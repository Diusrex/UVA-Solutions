#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Will return how many times it is for the current
unsigned long Calculate(unsigned long currentNumber, const int range, vector<int>& numberOfTimes)
{
//	cout << currentNumber << endl;
	if (currentNumber == 1 || (currentNumber < range && numberOfTimes[currentNumber] != 0))
	{
		return numberOfTimes[currentNumber];
	}
	
	unsigned long numberBefore;
	
	if (currentNumber % 2 == 0)
		numberBefore = Calculate(currentNumber / 2, range, numberOfTimes);
	
	else
		numberBefore = Calculate(currentNumber * 3 + 1, range, numberOfTimes);
		
	++numberBefore;
	
	if (currentNumber < range)
		numberOfTimes[currentNumber] = numberBefore;
	
	return numberBefore;
}

int main()
{
	const int range(1000001);
	vector<int> numberOfTimes(range, 0);
	
	numberOfTimes[1] = 1;
	
	for (int i = 2; i < range; ++i)
	{
		if (numberOfTimes[i] == 0)
		{
			//cout << "Origional: " << i << endl;
			numberOfTimes[i] = Calculate(i, range, numberOfTimes);
		}
	}
	
	string line;
	getline(cin, line);
	
	vector<int> allFirst, allSecond;
	vector<int> allMax;
	
	
	while (line != "")
	{
		stringstream temp;
		temp << line;
		
		int first, second;
		temp >> first >> second;
		
		int max(0);
		
		for (int i = first; i <= second; ++i)
		{
			if ( numberOfTimes[i] > max)
				max = numberOfTimes[i];
		}
		
		for (int i = second; i <= first; ++i)
		{
			if ( numberOfTimes[i] > max)
				max = numberOfTimes[i];
		}
		
		allFirst.push_back(first);
		allSecond.push_back(second);
		allMax.push_back(max);
		
		
		
		getline(cin, line);	
	}
	
	for (int i = 0; i < allFirst.size(); ++i)
		cout << allFirst[i] << " " << allSecond[i] << " " << allMax[i] << endl;
}
