#include <iostream>
#include <fstream>
#include "Query.h"
using std::ifstream;
using std::cout;
using std::endl;

int main()
{
	ifstream ifile("file");
	TextQuery t(ifile);
	Query q = Query("her") & ~Query("to") | Query("it") | Query("he");
	QueryResult rq = q.eval(t);
	cout << q.rep() << ":" << endl;
	print(cout, rq);
	return 0;
}
