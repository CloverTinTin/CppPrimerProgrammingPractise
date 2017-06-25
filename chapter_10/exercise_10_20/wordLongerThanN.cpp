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
    iter = stable_partition(words.begin(), words.end(), [n](const string &a){return a.size() >= n;});
    //cout << count_if(words.begin(), words.end(), [](const string &a){return a.size() > 6;}) << endl;
    //cout << count_if(words.begin(), words.end(), [](const string &a){return a.size() > 3;}) << endl;
    cout << count_if(words.begin(), words.end(), [](const string &a)->bool{if(a.size() > 3) return true; else return false;}) << endl;
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

    vector<int> nums{1,3,5,-1,-3,-5,6,7,0,-3};
    for_each(nums.begin(), nums.end(), [](int &num){cout << num << " ";});
    cout << endl;
    //transform(nums.begin(), nums.end(), nums.begin(), [](int a){return a < 0? -a: a;});
    transform(nums.begin(), nums.end(), nums.begin(), [](int a){if(a < 0) return -a; else return a;});
    for_each(nums.begin(), nums.end(), [](int &num){cout << num << " ";});
    cout << endl;
    

    return 0;
}
