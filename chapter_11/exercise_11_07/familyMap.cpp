#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    map<string, vector<string>> familyMap;
    familyMap["Jackson"] = vector<string>();
    familyMap["Jackson"].push_back("Tom");
    familyMap["Jackson"].push_back("Mike");
    for(const auto &name: familyMap)
    {
	cout << name.first << ": ";
	for_each(name.second.begin(), name.second.end(), [&](const string &name){cout << name << " ";});
    }
    cout << endl;
    return 0;
}
