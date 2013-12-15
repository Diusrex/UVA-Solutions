#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{

	int numberOfCases;

	cin >> numberOfCases;
	
	cout << setprecision(3) << fixed;
	
	for (int i = 0; i < numberOfCases; ++i)
	{
		int numberOfMarks;
		cin >> numberOfMarks;
		
		vector<double> marks(numberOfMarks);
		
		double total(0);
		
		for (int z = 0; z < numberOfMarks; ++z)
		{
			cin >> marks[z];
			total += marks[z];
		}
		
		const double average = total / numberOfMarks;
		
		int count(0);
		
		for (int z = 0; z < numberOfMarks; ++z)
		{
			if (marks[z] > average)
				count++;
		}
		
		double percent = count * 100.0 / numberOfMarks;		
		
		cout << percent << "%\n";
	}

}
