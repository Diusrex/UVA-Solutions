#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int numberOfSets;
	cin >> numberOfSets;

	int setNumber(1);

	while (numberOfSets != 0)
	{
		vector<int> array(numberOfSets);
		
		int total(0);

		for (int i = 0; i < numberOfSets; ++i)
		{
			cin >> array[i];
			total+=array[i];
		}

		int goal = total / numberOfSets;

		int count(0);
		for (int i = 0; i < numberOfSets; ++i)
		{
			if (array[i] > goal)
				count += array[i] - goal;
		}
		
		cout << "Set #" << setNumber << '\n';
		cout << "The minimum number of moves is " << count << ".\n\n";
		cin >> numberOfSets;
		++setNumber;
	}	

}

