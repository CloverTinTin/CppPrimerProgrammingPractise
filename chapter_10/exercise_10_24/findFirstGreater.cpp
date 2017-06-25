#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &word, const string::size_type sz)
{
    return word.size() > sz;
}

int main(int argc, char **argv)
{
    vector<string> words;
    for(int i = 1; i < argc; ++i)
	words.emplace_back(argv[i]);
    auto iter = find_if(words.begin(), words.end(), bind(check_size, _1, 6));
    cout << *iter << endl;
    return 0;
}
