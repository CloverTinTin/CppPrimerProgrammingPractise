#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, string> works = {{"author1", "work1"}, {"author1", "work2"}, 
	                              {"author2", "work3"}, {"author3", "work4"}, 
				      {"author1", "work5"}};
    for(auto &p: works)
	cout << p.first << " " << p.second << endl;
    cout << endl;
    auto iter = works.find("author1");
    if(iter != works.end())
	works.erase(works.equal_range("author1").first, works.equal_range("author1").second);
    for(auto &p: works)
	cout << p.first << " " << p.second << endl;
    return 0;
}
