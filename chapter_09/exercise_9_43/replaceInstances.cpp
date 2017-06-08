#include <iostream>
#include <string>
#include <iterator>
using namespace std;

void Replace(string &s, const string &oldVal, const string &newVal)
{
    for(auto iter = s.begin(); iter < s.end(); ++iter)
    {
	if(*iter != oldVal.front())
	    continue;
	if(string(iter, iter + oldVal.size()) == oldVal)
	{
	    auto offset = distance(s.begin(), iter);
	   // s.erase(offset, oldVal.size());
	   // s.insert(offset, newVal);
	    s.erase(iter, iter + oldVal.size());
	    s.insert(iter, newVal.cbegin(), newVal.cend());
	    iter = next(s.begin(), offset + newVal.size() - 1);
	}
    }
}

int main()
{
    string s("Replace tho, replace thru.");
    cout << s << endl;
    Replace(s, "tho", "though");
    cout << s << endl;
    Replace(s, "thru", "through");
    cout << s << endl;
}
