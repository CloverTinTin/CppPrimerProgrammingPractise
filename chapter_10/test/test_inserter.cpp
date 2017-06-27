#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3;
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    for_each(lst2.cbegin(), lst2.cend(), [](int i){cout << i << " ";});
    cout << endl;
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    for_each(lst3.cbegin(), lst3.cend(), [](int i){cout << i << " ";});
    cout << endl;
}
