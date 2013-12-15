#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main()
{
	
	string line;
	getline(cin, line);
	
	vector<long> difference;
	
	while (line != "")
	{
		stringstream temp;
		temp << line;
		
		long first, second;
		
		temp >> first >> second;
		
		difference.push_back(abs(first - second));
		getline(cin, line);
	}
	
	for (int i = 0; i < difference.size(); ++i)
		cout << difference[i] << endl;
}
