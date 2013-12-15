#include <iostream>
#include <vector>

using namespace std;


int main()
{

	int xSize, ySize;

	cin >> xSize >> ySize;

	for (int count = 1; xSize != 0 && ySize != 0; ++count)
	{
		if (count != 1)
			cout << '\n';
			
		vector<vector<int> > mineCount(xSize + 2, vector<int>(ySize + 2, 0));
		
		for (int x = 1; x <= xSize; ++x)
		{
			string temp;
			cin >> temp;
			
			for (int y = 1; y <= ySize; ++y)
			{
				if (temp[y - 1] == '*')
				{
					mineCount[x][y] = 10;
					for (int xc = -1; xc < 2; ++xc)
					{
						for (int yc = -1; yc < 2; ++yc)
						{
							//if (x + xc >= 0 && x + xc < xSize && y + yc >= 0 && y + yc < ySize)
							++mineCount[x + xc][y + yc];
						}
					}
				}
			}
		}

		cout << "Field #" << count << ":\n";

		for (int x = 1; x <= xSize; ++x)
		{
			for (int y = 1; y <= ySize; ++y)
			{
				if (mineCount[x][y] > 10)
					cout << '*';
				else
					cout << mineCount[x][y];
			}
			cout << '\n';
		}
		
		

		cin >> xSize >> ySize;	

	}

}
