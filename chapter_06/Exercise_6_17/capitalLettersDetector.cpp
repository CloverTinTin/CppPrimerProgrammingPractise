#include <iostream>
#include <string>
#include <iterator>
#include <cctype>
using namespace std;

bool capitalDetector(const string &str)
{
    for(string::const_iterator i = str.begin(); i < str.end(); ++i)
	if(isupper(*i))
	    return true;
    return false;
}

void changeToLowercase(string &str)
{
    for(auto i = str.begin(); i < str.end(); ++i)
	*i = tolower(*i);
}

int main()
{
    string str;
    cin >> str;

    if(capitalDetector(str) == true)
    {
	cout << "find capital.\n";
	changeToLowercase(str);
    }
    cout << str << endl;
    return 0;
}
