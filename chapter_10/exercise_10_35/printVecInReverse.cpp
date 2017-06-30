#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    for(auto iter = vec.end() - 1; iter >= vec.begin(); --iter)
	cout << *iter << " ";
    cout << endl;
}
