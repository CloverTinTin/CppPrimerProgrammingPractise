#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> Vint;
	int temp;

	while(cin >> temp)
		Vint.push_back(temp);
	for(decltype(Vint.size()) i = 0; i < Vint.size(); ++i)
		cout << Vint[i] << " ";
	cout << endl;
	return 0;
}
