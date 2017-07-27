#include <iostream>
#include <string>
using namespace std;

int main()
{
    char *buff = new char[25], *ptr = buff;
    string str;
    while(cin >> str)
    {
	for(int i = 0; i < str.size(); ++i)
	    *(ptr++) = str[i];
	*(ptr++) = ' ';
    }
    cout << buff << endl;
}
