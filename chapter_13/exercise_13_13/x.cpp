#include <iostream>
#include <vector>
using namespace std;

struct X
{
	X(){cout << "X()" << endl;}
	X(const X &x) {cout << "X(const X &x)" << endl;}
	~X() {cout << "~X" << endl;}
	X &operator=(const X &x){cout << "operator=" << endl; return *this;}

	int member = 0;
};

void reference(X &x)
{
	cout << "reference(X &x)" << endl;
}

void noReference(X x)
{
	cout << "no reference(X x)" << endl;
}

int main()
{
	cout << "define a X:" << endl;
	X x1;
	cout << "copy initial:" << endl;
	X x2 = x1;
	cout << "call reference:" << endl;
	reference(x1);
	cout << "call noReference:" << endl;
	noReference(x1);
	vector<X> xVec;
	cout << "push into vector" << endl;
	xVec.push_back(x1);
}
