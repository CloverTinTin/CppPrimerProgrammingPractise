#include <iostream>
#include <string>
using namespace std;

string::size_type find_char(const string &str, char c, string::size_type &occurs)
{
    auto ret = str.size();

    occurs = 0;
    for(decltype(ret) i = 0; i < str.size(); ++i)
	if(str[i] == c)
	{
	    ++occurs;
	    if(ret == str.size())
		ret = i;
	}
    return ret;
}

int main()
{
    string str;
    char c;
    cin >> str >> c;

    string::size_type occurs = 0;
    string::size_type firstPos = find_char(str, c, occurs);
    cout << "'" << c <<  "' first occurs at positon " << firstPos << ", it occurs " << occurs << " times." << endl;
    return 0;
}
