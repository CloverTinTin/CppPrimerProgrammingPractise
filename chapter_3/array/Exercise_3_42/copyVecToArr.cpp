#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec{3,1,4,1,5,9};
    int ia[6];

    auto i = ivec.begin();
    for(auto p = begin(ia), q = end(ia); p != q; ++p)
    {
	*p = *i;
	++i;
    }
    for(auto element: ia)
	cout << element <<  " ";
    cout << endl;

    int test = 0;
    int test2 = 3;
    int* const ptr = &test;
    auto temp = ptr;
    temp = &test2;
    cout << *temp << endl;
    return 0;
}
