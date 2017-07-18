#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    int i;
    vector<pair<string, int>> pairVec_1, pairVec_2, pairVec_3, pairVec_4;
    while(cin >> str >> i)
    {
	pairVec_1.push_back({str, i});
	pairVec_2.push_back(make_pair(str, i));
	pairVec_3.push_back(pair<string, int>(str, i));
	pairVec_4.emplace_back(str, i);
    }
    for(auto &p: pairVec_1)
	cout << p.first << " " << p.second << " / ";
    cout << endl;
    for(auto &p: pairVec_2)
	cout << p.first << " " << p.second << " / ";
    cout << endl;
    for(auto &p: pairVec_3)
	cout << p.first << " " << p.second << " / ";
    cout << endl;
    for(auto &p: pairVec_4)
	cout << p.first << " " << p.second << " / ";
    cout << endl;
    return 0;
}
