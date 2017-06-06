#include <iostream>
using namespace std;

void f()
{
    cout << "f(void)" << endl;
}

void f(int i)
{
    cout << "f(int i)" << endl;
}

void f(int i, int j)
{
    cout << "f(int i, int j)" << endl;
}

void f(double i, double j = 3.14)
{
    cout << "f(double i, double j = 3.14)" << endl;
}

int main()
{
//    f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    return 0;
}
