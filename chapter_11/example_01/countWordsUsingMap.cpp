#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    istream_iterator<string> input_iter(cin), end_iter;
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "and"};
    for_each(input_iter, end_iter, [&](const string &word){if(exclude.find(word) == exclude.end()) ++word_count[word];});
    for(const auto &word: word_count)
	cout << word.first << " occurs " << word.second << (word.second > 1? " times": " time") << endl; 
    return 0;
}
