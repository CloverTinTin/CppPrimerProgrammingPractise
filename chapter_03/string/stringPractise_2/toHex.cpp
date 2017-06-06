#include <iostream>
#include <string>
using namespace std;

int main()
{
	const string hexDigit("0123456789ABCDEF");
	string line;
	decltype(hexDigit.size()) n;

	for(auto &c: hexDigit)
		cout << c;
	cout << '\n';

	while(cin >> n)
		if(n < hexDigit.size())
			line += hexDigit[n];
	cout << line << endl;
}
