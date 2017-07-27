#include <iostream>
using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = std::string()): ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &h): i(h.i), ps(new string(*h.ps)) { }
private:
    string *ps;
    int i;
}

