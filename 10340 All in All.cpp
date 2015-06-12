#include <iostream>
#include <string>

using namespace std;

int main()
{
	string first, second;
	
	while (cin >> first >> second)
	{
		string::iterator fIter = first.begin(), sIter = second.begin();
		
		for (; sIter != second.end(); ++sIter)
		{
			if (*fIter == *sIter)
			{
				++fIter;
				if (fIter == first.end())
					break;
			}
		}
		
		if (fIter == first.end())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}