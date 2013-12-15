#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	vector<vector< int> > array(n, vector<int>(n));
	
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
			cin >> array[x][y];
	}
	
	int max(array[0][0]);
	
	// Is just out here to decrease the number of times it needs to be redefined
	vector<vector<int> > previousValues(n, vector<int>(n));

	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			for (int xc = 0; xc < n - x; ++xc)
			{
				int currentColumnCount(0);
				
				for (int yc = 0; yc < n - y; ++yc)
				{
					currentColumnCount+= array[x + xc][y + yc];
					
					int currentTotal(currentColumnCount);
				
					if (xc != 0)
						currentTotal += previousValues[x + xc - 1][y + yc];
						
					previousValues[x + xc][y + yc] = currentTotal;
					
					if (currentTotal > max)
						max = currentTotal;
				}
			}
			
		}
	}
	
	cout << max << endl;
}
