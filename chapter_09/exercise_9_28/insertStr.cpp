#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

void insertStr(forward_list<string> &flist, const string &str1, const string &str2)
{
    auto prev = flist.before_begin();
    auto cur = flist.begin();
    while(cur != flist.end())
    {
	if(*cur == str1)
	{
	    flist.insert_after(cur, str2);
	    return;
	}
	else
	{
	    prev = cur;
	    ++cur;
	}
    }
    flist.insert_after(prev, str2);
}

int main()
{
    forward_list<string> flist = {"abc", "def", "jkl", "mn"};
    for(auto str: flist)
	cout << str << " ";
    cout << endl;
    insertStr(flist, "def", "ghi");
    for(auto str: flist)
	cout << str << " ";
    cout << endl;
    return 0;
}
