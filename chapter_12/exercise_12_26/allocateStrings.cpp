#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main()
{
    allocator<string> a;
    auto const p = a.allocate(100);
    auto q = p;
    string str;
    while(cin >> str && q != p + 100)
	a.construct(q++, str);
    const size_t size = q - p;
    for(size_t i = 0; i < size; ++i)
    {
	cout << *(p + i) << endl;
	a.destroy(p + i);
    }
    a.deallocate(p, 100);
    return 0;
}
