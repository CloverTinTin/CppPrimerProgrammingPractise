#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	string tempstr;
	vector<string> strvector;

	while(cin >> tempstr)
		strvector.push_back(tempstr);
	for(string &str: strvector)
		for(auto &c: str)
			c = toupper(c);
	int i = 0;
	for(string str: strvector)
	{
		cout << str << " ";
		if(++i >= 3)
		{
			i = 0;
			cout << '\n';
		}
	}
	cout << endl;
	return 0;
}
