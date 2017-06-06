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

int main(int argc, char **argv)
{
    int i = stoi(argv[1]);
    
    for(int j = 0; j < 10; ++j)
	cout << arrReference(i)[j] << endl;
    return 0;
}
