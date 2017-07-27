#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class QueryResult;

class TextQuery
{
public:
    TextQuery();
    TextQuery(ifstream &infile);
    QueryResult query(const string& word) const;

private:
    shared_ptr<vector<string>> file;
    shared_ptr<map<string, set<int>>> index;
};

class QueryResult
{
public:
    QueryResult();
    QueryResult(shared_ptr<vector<string>> f, shared_ptr<map<string, set<int>>> i, const string &key):file(f), index(i), keyWord(key){ }
    shared_ptr<vector<string>> file;
    shared_ptr<map<string, set<int>>> index;
    string keyWord;
};

TextQuery::TextQuery(ifstream &infile)
{
    file = make_shared<vector<string>>();
    index = make_shared<map<string, set<int>>>();
    int lineNum = 0;
    string line, word;
    while(getline(infile, line))
    {
	file->push_back(line);
	istringstream inputStr(line);
	while(inputStr >> word)
	    (*index)[word].insert(lineNum);
	++lineNum;
    }
}

QueryResult TextQuery::query(const string &word) const
{
    return QueryResult(file, index, word);
}

ostream &print(ostream &out, QueryResult qr)
{
    for(int i: (*qr.index)[qr.keyWord])
	out << i << ": " << (*qr.file)[i] << endl;
    return out;
}

int main()
{
    ifstream infile("file");
    TextQuery tq(infile);
    while(true)
    {
	cout << "enter word to look for, or q to quit: ";
	string s;
	if(!(cin >> s) || s == "q") break;
	print(cout, tq.query(s)) << endl;
    }
    return 0;
}



