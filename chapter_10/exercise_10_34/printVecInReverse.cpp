#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    for_each(vec.crbegin(), vec.crend(), [](const int i){cout << i << " ";});
    ostream_iterator<int> outIter(cout, " ");
    cout << endl;
    copy(vec.crbegin(), vec.crend(), outIter);
    cout << endl;
}
