#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
using namespace std::placeholders;

bool check_size(const string &word, const string::size_type n)
{
    return word.size() > n;
}

void findLongerThanN(vector<string> &words, string::size_type n)
{
    sort(words.begin(), words.end());
    auto iter = unique(words.begin(), words.end());
    words.erase(iter, words.end());
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    //iter = partition(words.begin(), words.end(), [n](const string &a){return a.size() >= n;});
    iter = partition(words.begin(), words.end(), bind(check_size, _1, n));
    cout << iter - words.begin() << endl;
    for_each(words.begin(), iter, [](const string &word){cout << word << " ";});
    cout << endl;
}

int main(int argc, char **argv)
{
    if(argc <= 2)
    {
	cerr << "error: want more arguments.\n";
	return -1;
    }
    string::size_type n = stoi(argv[1]);
    vector<string> words;
    for(int i = 2; i < argc; ++i)
	words.emplace_back(argv[i]);
    for_each(words.begin(), words.end(), [](string &word){cout << word << " ";});
    cout << endl;
    findLongerThanN(words, n);
    for_each(words.begin(), words.end(), [](string &word){cout << word << " ";});
    cout << endl;
    return 0;
}
