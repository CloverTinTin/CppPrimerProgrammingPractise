#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string sa("helloworld");
    string sb("helloearth");

    if(sa == sb)
	cout << "equal string\n";
    else
	cout << "not equal\n";

    char ca[] = "hello";
    char cb[] = "hello";
    if(strcmp(ca, cb) == 0)
	cout << "equal c-type string\n";
    else
	cout << "not equal c-type string\n";
    return 0;
}
