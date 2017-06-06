#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> intVector;
    int temp;

    while(cin >> temp)
	intVector.push_back(temp);
    for(auto iter = intVector.cbegin(); iter != intVector.cend() - 1; ++iter)
	cout << *iter << " + " << *(iter + 1) << " = " << *iter + *(iter + 1) << '\n';
    cout << endl;

    for(auto liter = intVector.cbegin(), riter = intVector.cend() - 1; liter < riter; ++liter, --riter)
	cout << *liter << " + " << *riter << " = " << *liter + *riter << '\n';
    return 0;
}
