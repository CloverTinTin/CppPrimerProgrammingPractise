#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    map<string, size_t> word_count;
    set<string> exclude = {"the", "but", "and"};
    string word;
    while(cin >> word)
    {
	for(auto iter = word.begin(); iter < word.end(); ++iter)
	    if(isalpha(*iter))
		*iter = tolower(*iter);
	    else
	    {
		iter = word.erase(iter);
		--iter;
	    }
	if(exclude.find(word) == exclude.end())
	    ++word_count[word];
    }
    for(const auto &word: word_count)
	cout << word.first << " occurs " << word.second << (word.second > 1? " times": " time") << endl; 
    return 0;
}
