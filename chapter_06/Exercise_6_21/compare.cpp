#include <iostream>
using namespace std;

int getLarger(int a, const int *b)
{
    return a > *b? a: *b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << getLarger(a, &b) << endl;
    return 0;
}
