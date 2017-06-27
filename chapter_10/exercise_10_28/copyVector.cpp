#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3;
    copy(vec.begin(), vec.end(), inserter(lst1, lst1.begin()));
    copy(vec.begin(), vec.end(), back_inserter(lst2));
    copy(vec.begin(), vec.end(), front_inserter(lst3));
    auto f = [](list<int> &l){for_each(l.begin(), l.end(), [](int i){cout << i << " ";}); cout << endl;};
    cout << "inserter back_inserter front_inserter" << endl;
    f(lst1); f(lst2); f(lst3);
    return 0;
}
