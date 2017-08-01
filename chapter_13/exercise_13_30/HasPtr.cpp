#include <iostream>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr &a, HasPtr &b);
public:
    HasPtr(const string &s = std::string()): ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &h): i(h.i), ps(new string(*h.ps)) { }
    HasPtr &operator=(const HasPtr &hasptr)
    {
	auto newp = new string(*hasptr.ps);
	i = hasptr.i;
	delete ps;
	ps = newp;
	return *this;
    }
    ~HasPtr()
    {
	delete ps;
    }
    const string &str() {return *ps;}
private:
    string *ps;
    int i;
};

void swap(HasPtr &a, HasPtr &b)
{
	using std::swap;
	swap(a.ps, b.ps);
	swap(a.i, b.i);
	cout << "use swap" << endl;
}

int main()
{
	HasPtr a("a"), b("b");
	cout << a.str() << endl;
	cout << b.str() << endl;
	swap(a, b);
	cout << a.str() << endl;
	cout << b.str() << endl;
	return 0;
}














