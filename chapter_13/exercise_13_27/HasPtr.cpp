#include <iostream>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = std::string()): ps(new string(s)), user_counter(new size_t(1)), i(0) { }
    HasPtr(const HasPtr &h): i(h.i), user_counter(h.user_counter), ps(h.ps)
    {
	    ++*user_counter;
    }
    HasPtr &operator=(HasPtr &hasptr)
    {
	++*hasptr.user_counter;
	if(--*user_counter == 0)
	{
		delete ps;
		delete user_counter;
	}
	ps = hasptr.ps;
	user_counter = hasptr.user_counter;
	i = user_counter.i;
	return *this;
    }
    ~HasPtr()
    {
	if(--*user_counter == 0)
	{
	    delete ps;
	    delete user_counter;
	}
    }
private:
    string *ps;
    size_t *user_counter;
    int i;
}
