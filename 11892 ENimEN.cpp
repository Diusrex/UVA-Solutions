#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		
		bool allOne(true);
		for (int z = 0; z < N; ++z)
		{
			unsigned long temp;
			
			cin >> temp;
			
			if (temp != 1)
				allOne = false;
		}
		
		if (allOne && N % 2 == 0)
			cout << "piloop\n";
		
		else
			cout << "poopi\n";
	}

}