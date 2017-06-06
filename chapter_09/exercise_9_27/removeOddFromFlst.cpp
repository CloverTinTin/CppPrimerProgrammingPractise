#include <iostream>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> flist = {1,2,3,4,5,6,7,8,9};
    auto prev = flist.before_begin();
    auto cur = flist.begin();
    while(cur != flist.end())
    {
	if((*cur & 1) != 0)
	    cur = flist.erase_after(prev);
	else
	{
	    prev = cur;
	    ++cur;
	}
    }
    for(auto i: flist)
	cout << i << " ";
    cout << endl;
    return 0;
}
