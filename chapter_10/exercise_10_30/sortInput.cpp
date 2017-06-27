#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), end_iter;
    vector<int> nums(in_iter, end_iter);
    sort(nums.begin(), nums.end());
    ostream_iterator<int> out_iter(cout, " ");
    copy(nums.begin(), nums.end(), out_iter);
    cout << endl;
    return 0;
}
