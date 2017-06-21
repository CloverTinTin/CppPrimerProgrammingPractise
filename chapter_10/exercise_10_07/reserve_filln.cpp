#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
//    vec.reserve(10);
//    vec.resize(10);
    cout << vec.capacity() << endl;
//    fill_n(vec.begin(), 10, 0);
    fill_n(back_inserter(vec), 10, 0);
    for(auto i: vec)
	cout << i << " ";
    cout << endl;
    return 0;
}
