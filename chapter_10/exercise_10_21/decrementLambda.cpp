#include <iostream>
using namespace std;

int main()
{
    int n = 10;
    cout << n << endl;
    auto f = [&](){if(n != 0){while(n > 0) --n; return false;} return true;};
    cout << boolalpha << f() << endl;
    cout << n << endl;
    return 0;
}
