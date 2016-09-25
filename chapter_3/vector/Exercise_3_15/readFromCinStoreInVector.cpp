#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> Vstr;
        string temp;

	while(getline(cin, temp))
		Vstr.push_back(temp);
	for(decltype(Vstr.size()) i = 0; i < Vstr.size(); ++i)
		cout << Vstr[i] << endl;
	return 0;
}
