#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<unsigned> scores(11, 0);
	unsigned temp;

	while(cin >> temp)
		if(temp <= 100)
			++scores[temp / 10];
	for(decltype(scores.size()) i = 0; i < 11; ++i)
		cout << scores[i] << " ";
	cout << endl;
	return 0;
}
