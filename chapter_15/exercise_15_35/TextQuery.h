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
    shared_ptr<map<string, set<int>>> index;

private:
    shared_ptr<vector<string>> file;
};

class QueryResult
{
public:
    QueryResult();
    QueryResult(shared_ptr<vector<string>> f, const set<int> &i, const string &key):file(f), index(i), keyWord(key){ }
    shared_ptr<vector<string>> file;
    set<int> index;
    string keyWord;
    set<int>::iterator begin() {return index.begin();}
    set<int>::iterator end() {return index.end();}
    shared_ptr<vector<string>> get_file() {return file;}
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
    return QueryResult(file, (*index)[word], word);
}

ostream &print(ostream &out, QueryResult &qr)
{
    for(int i: qr.index)
	out << i << ": " << (*qr.file)[i] << endl;
    return out;
}


