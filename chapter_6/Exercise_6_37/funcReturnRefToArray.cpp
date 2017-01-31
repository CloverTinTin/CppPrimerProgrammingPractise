#include <iostream>
#include <string>
using namespace std;

string strArr1[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};
string strArr2[10] = {"k", "l", "m", "n", "o", "p", "q", "r", "s", "t"};

string (&arrReference(int i))[10]
{
    if(i == 0)
	return strArr1;
    else
	return strArr2;
}

using strArr = string[10];

strArr &arrReference_useTypeAlias(int i)
{
    if(i == 0)
	return strArr1;
    else
	return strArr2;
}

decltype(strArr1) &arrReference_useDecltype(int i)
{
    if(i == 0)
	return strArr1;
    else
	return strArr2;
}

auto arrReference_useTrailingReturn(int i)->string (&)[10]
{
    if(i == 0)
	return strArr1;
    else
	return strArr2;
}

int main(int argc, char **argv)
{
    int i = stoi(argv[1]);
    
    for(int j = 0; j < 10; ++j)
	cout << arrReference(i)[j] << " ";
    cout << endl;

    for(int j = 0; j < 10; ++j)
	cout << arrReference_useTypeAlias(i)[j] << " ";
    cout << endl;

    for(int j = 0; j < 10; ++j)
	cout << arrReference_useDecltype(i)[j] << " ";
    cout << endl;

    for(int j = 0; j < 10; ++j)
	cout << arrReference_useTrailingReturn(i)[j] << " ";
    cout << endl;
    return 0;
}



