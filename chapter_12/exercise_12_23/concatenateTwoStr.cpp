#include <iostream>
#include <string>
using namespace std;

char *concatenate(const string &str1, const string &str2)
{
    int n = str1.size() + str2.size();
    char *ret = new char[n];
    char *ptr = ret;
    for(int i = 0; i < str1.size(); ++i)
	*(ptr++) = str1[i];
    for(int i = 0; i < str2.size(); ++i)
	*(ptr++) = str2[i];
    return ret;
}

int main()
{
    char *str = concatenate("abc", "def");
    cout << str << endl;
    string str1("abc"), str2("def");
    cout << str1 + str2 << endl;
    return 0;
}
