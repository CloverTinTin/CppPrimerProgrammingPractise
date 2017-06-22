#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void findLongerThanN(vector<string> &words, string::size_type n)
{
    sort(words.begin(), words.end());
    auto iter = unique(words.begin(), words.end());
    words.erase(iter, words.end());
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){return a.size() < b.size();});
    iter = find_if(words.begin(), words.end(), [n](const string &a){return a.size() >= n;});
    cout << words.end() - iter << endl;
    for_each(iter, words.end(), [](const string &word){cout << word << " ";});
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
