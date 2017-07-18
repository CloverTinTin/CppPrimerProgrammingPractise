#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, string> works = {{"author1", "work1"}, {"author1", "work2"}, 
	                              {"author2", "work3"}, {"author3", "work4"}, 
				      {"author1", "work5"}};
    auto iter = works.begin();
    while(iter != works.end())
    {
	string author = iter->first;
	cout << author << ":\n";
	for(iter = works.lower_bound(author); iter != works.upper_bound(author); ++iter)
	    cout << "   " << iter->second << endl;
    }
    return 0;
}
