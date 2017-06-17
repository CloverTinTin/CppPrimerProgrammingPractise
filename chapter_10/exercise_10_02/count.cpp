#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    list<string> strl;
    string str; 

    string object(argv[1]);
    while(cin >> str)
	strl.push_back(str);
    cout << count(strl.begin(), strl.end(), object) << endl;
    return 0;
}
