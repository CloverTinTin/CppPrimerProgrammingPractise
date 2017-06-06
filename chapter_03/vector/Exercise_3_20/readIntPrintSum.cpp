#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers;
	int temp;

	while(cin >> temp)
		numbers.push_back(temp);
	decltype(numbers.size()) size = numbers.size();
	int i, j;
	for(i = 0; i < size - 1; ++i)
		cout << numbers[i] << " + " << numbers[i + 1] << " = " << numbers[i] + numbers[i + 1] << endl;
	cout << endl;
	for(i = 0, j = size - 1; j > i; ++i, --j)
		cout << numbers[i] << " + " << numbers[j] << " = " << numbers[i] + numbers[j] << endl;
	return 0;
}
