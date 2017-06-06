#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

void fastSortString(vector<string>::iterator begin, vector<string>::iterator end);

int main(int argc, char **argv)
{
    ifstream file(argv[1]);
    vector<string> strVector;
    string temp;

    while(file >> temp)
	strVector.push_back(temp);
    fastSortString(strVector.begin(), strVector.end());
    for(auto s: strVector)
	cout << s << ' ';
    cout << endl;
    string target = argv[2];
    auto begin = strVector.begin(), end = strVector.end();
    auto mid = begin + (end - begin) / 2;
    while(mid != end)
    {
	if(*mid == target)
	{
	    cout << target << " is existing\n";
	    return 0;
	}
	if(*mid > target)
	    end = mid;
	else
	    begin = mid + 1;
	mid = begin + (end - begin) / 2;
    }
    cout << "can't find " << target << endl;
    return 0;
}

void swap(vector<string>::iterator a, vector<string>::iterator b)
{    
    string temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void fastSortString(vector<string>::iterator begin, vector<string>::iterator end)
{
    if(begin >= end)
	return;
    auto smallEndIter = begin;
    for(auto i = begin + 1; i < end; ++i)
	if(*i <= *begin)
	    swap(i, ++smallEndIter);
    swap(begin, smallEndIter);
    fastSortString(begin, smallEndIter);
    fastSortString(smallEndIter + 1, end);
}









