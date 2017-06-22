#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void elimDups(vector<string> &vec)
{
    cout << "Original vector content:\n";
    for(auto &str: vec)
	cout << str << " ";
    cout << endl;
    sort(vec.begin(), vec.end());
    cout << "Sort vector content:\n";
    for(auto &str: vec)
	cout << str << " ";
    cout << endl;
    auto iter = unique(vec.begin(), vec.end());
    cout << "Unique vector content:\n";
    for(auto &str: vec)
	cout << str << " ";
    cout << endl;
    vec.erase(iter, vec.end());
    cout << "Erase vector content:\n";
    for(auto &str: vec)
	cout << str << " ";
    cout << endl;
}

bool isShorter(const string &a, const string &b)
{
    return a.size() < b.size();
}

int main(int argc, char **argv)
{
    vector<string> vec;
    for(int i = 1; i < argc - 1; ++i)
	vec.push_back(string(argv[i]));
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    cout << "Stable sort:\n";
    for(auto &str: vec)
	cout << str << " ";
    cout << endl;
    return 0;
}
