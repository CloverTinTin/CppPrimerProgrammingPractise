#include <iostream>
using namespace std;

template<typename T> void reset(T &a)
{
    a = 0;
}

int main()
{
    int a;
    cin >> a;
    reset(a);
    cout << a << endl;
    return 0;
} 
