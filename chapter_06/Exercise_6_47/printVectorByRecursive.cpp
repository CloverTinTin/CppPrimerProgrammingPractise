#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int> &vec, const int size, int pos)
{
    if(pos < size)
    {
	cout << vec[pos] << " ";
#ifndef NDEBUG

	cout << pos << endl;

#endif
    	printVector(vec, size, pos + 1);
    }
}

int main()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };
    printVector(vec, vec.size(), 0);
    cout << endl;
    return 0;
}
