#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    int i;
    vector<pair<string, int>> pairVec;
    while(cin >> str >> i)
	pairVec.push_back({str, i});
    for(auto &p: pairVec)
	cout << p.first << " " << p.second << endl;
    return 0;
}
