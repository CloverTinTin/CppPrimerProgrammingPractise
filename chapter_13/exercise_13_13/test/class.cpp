#include <iostream>
using namespace std;

struct X
{
	X(int a): member(a) {}
	X &operator=(const X &x){member = x.member; cout << "operator=" << endl;} 

	int member;
};

void f(X x)
{
	cout << x.member << endl;
}

int main()
{
	f(1);
	X x(2);
	f(x);
	x = 3;
	f(x);
	return 0;
}
