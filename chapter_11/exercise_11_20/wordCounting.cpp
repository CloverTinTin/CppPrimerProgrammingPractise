#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string word;
    map<string, int> counter;
    
    while(cin >> word)
	++counter.insert({word, 0}).first->second;
    for(auto &w: counter)
	cout << w.first << " : " << w.second << endl;
    return 0;
}
