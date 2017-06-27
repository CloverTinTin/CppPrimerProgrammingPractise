#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int main()
{
    vector<int> vec = {3,3,6,2,2,2,5,4,8,7,4,3,2,1,8};
    sort(vec.begin(), vec.end());
    list<int> lst;
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));
    for_each(lst.begin(), lst.end(), [](int i){cout << i << " ";});
    cout << endl;
}
