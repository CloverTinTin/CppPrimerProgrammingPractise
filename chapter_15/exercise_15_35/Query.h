#include "TextQuery.h"
#include <memory>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
using std::string;
using std::shared_ptr;
using std::set;
using std::set_intersection;
using std::inserter;

class Query_base
{
	friend class Query;
protected:
	virtual ~Query_base() = default;

private:
	virtual QueryResult eval(const TextQuery &) const = 0;
	virtual string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator&(const Query &, const Query &);
	friend Query operator|(const Query &, const Query &);
public:
	Query(const string &);
	QueryResult eval(const TextQuery &t) const {return q->eval(t);}
	string rep() const {return q->rep();}

private:
	Query(shared_ptr<Query_base> query): q(query) { }
	shared_ptr<Query_base> q;
};

class WordQuery: public Query_base
{
	friend class Query;
	WordQuery(const string &s): query_word(s) { }
	QueryResult eval(const TextQuery &t) const override { return t.query(query_word);}
	string rep() const override { return query_word;}
	string query_word;
};

inline Query::Query(const string &s): q(new WordQuery(s)) { }

class NotQuery: public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q): query(q) { }	
	QueryResult eval(const TextQuery &t) const override;
	string rep() const override { return "~(" + query.rep() + ")"; }
	Query query;
};

QueryResult NotQuery::eval(const TextQuery &t) const
{
	QueryResult q = query.eval(t);
	int size = q.get_file()->size();
	auto begin = q.begin(); 
	auto end = q.end();
	set<int> lines;
	for(int i = 0; i < size; ++i)
		if(begin == end || i != *begin)
			lines.insert(i);
		else if(begin != end)
			++begin;
	return QueryResult(q.get_file(), lines, rep());
}

inline Query operator~(const Query &q)
{
	return shared_ptr<Query_base>(new NotQuery(q));
}

class BinaryQuery: public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, const string &s): left(l), right(r), symbol(s) { }
	string rep() const override {return "(" + left.rep() + " " + symbol + " " + right.rep() + ")";}
	Query left, right;
	string symbol;
};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query &, const Query &);
	AndQuery(const Query &l, const Query &r): BinaryQuery(l, r, "&") { }
	QueryResult eval(const TextQuery &) const override;
};

QueryResult AndQuery::eval(const TextQuery &q) const 
{
	QueryResult l = left.eval(q), r = right.eval(q);
	set<int> lines;
	set_intersection(l.begin(), l.end(), r.begin(), r.end(), inserter(lines, lines.begin()));
	return QueryResult(l.get_file(), lines, rep());
}

inline Query operator&(const Query &l, const Query &r)
{
	return shared_ptr<Query_base>(new AndQuery(l, r));
}

class OrQuery: public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &l, const Query &r): BinaryQuery(l, r, "|") { }
	QueryResult eval(const TextQuery &) const override;
};

inline Query operator|(const Query &l, const Query &r)
{
	return shared_ptr<Query_base>(new OrQuery(l, r));
}

QueryResult OrQuery::eval(const TextQuery &q) const
{
	QueryResult l = left.eval(q), r = right.eval(q);
	set<int> lines(l.begin(), l.end());
	lines.insert(r.begin(), r.end());
	return QueryResult(l.get_file(), lines, rep());
}
















