#include <iostream>
using namespace std;

template<typename T> void mySwap(T &a, T &b)
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}

int main()
{
    double a, b;
    int c, d;

    cin >> a >> b;
    mySwap(a, b);
    cout << a << " " << b << endl;
    cin >> c >> d;
    mySwap(c, d);
    cout << c << " " << d << endl;
    return 0;
}
