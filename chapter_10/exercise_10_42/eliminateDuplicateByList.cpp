#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    list<int> lst(in_iter, eof);
    lst.sort();
    lst.unique();
    //for_each(lst.begin(), lst.end(), [](int i){cout << i << " ";});
    copy(lst.begin(), lst.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
