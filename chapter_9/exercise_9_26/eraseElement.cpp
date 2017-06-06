#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(ia, end(ia));
//    list<int> lst(vec.begin(), vec.end());
    list<int> lst(ia, end(ia));
    auto iter = vec.begin();
    while(iter != vec.end())
    {
	if((*iter & 1) == 0)
	    iter = vec.erase(iter);
	else
	    ++iter;
    }
    auto liter = lst.begin();
    while(liter != lst.end())
    {
	if((*liter & 1) != 0)
	    liter = lst.erase(liter);
	else
	    ++liter;
    }
    for(auto i: vec)
	cout << i << " ";
    cout << endl;
    for(auto i: lst)
	cout << i << " ";
    cout << endl;
    return 0;
}
