#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    string previous;

    while(cin >> str)
    {
	if(str == previous)
	{
	    if(!isupper(str[0]))
		continue;
	    cout << str << " occurs twice in succession\n";
	    break;
	}
	previous = str;
    }
    if(!cin)
	cout << "No word was repeated.\n";
    return 0;
}
