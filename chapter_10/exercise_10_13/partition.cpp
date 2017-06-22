#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool hasMoreThanFive(const string &word)
{
    return word.size() >= 5;
}

int main(int argc, char **argv)
{
    vector<string> words;
    for(int i = 1; i < argc; ++i)
	words.emplace_back(argv[i]);
    auto iter = partition(words.begin(), words.end(), hasMoreThanFive);
    for(auto i = words.begin(); i < iter; ++i)
	cout << *i << " ";
    cout << endl;
    return 0;
}
