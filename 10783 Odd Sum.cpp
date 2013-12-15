#include <iostream>

using namespace std;

int main()
{
	int numberOfCases;
	
	cin >> numberOfCases;
	
	for (int i = 0; i < numberOfCases; ++i)
	{
		int start, end;
		cin >> start >> end;
		
		
		int count(0);
		if (start % 2 == 0)
			start++;
			
		for (int z = start; z <= end; z += 2)
			count += z;
		
		cout << "Case " << i + 1 << ": " << count << endl;
	}
}
