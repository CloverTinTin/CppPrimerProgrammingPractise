#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr &a, HasPtr &b);
    friend bool operator<(const HasPtr &a, const HasPtr &b);
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
	cout << "swap " << *a.ps << " " << *b.ps << endl;
	swap(a.ps, b.ps);
	swap(a.i, b.i);
}

bool operator<(const HasPtr &a, const HasPtr &b)
{
    return *a.ps < *b.ps;
}

int main()
{
	vector<HasPtr> hvector{HasPtr("a"), HasPtr("c"), HasPtr("b"), HasPtr("h")};
	sort(hvector.begin(), hvector.end());
	for(auto h: hvector)
		cout << h.str() << " ";
	cout << endl;
	return 0;
}














