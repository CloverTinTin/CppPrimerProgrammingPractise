#include <iostream>
using namespace std;

int absolute(int num)
{
    return num < 0? -num: num;
}

int main()
{
    int i = -5;

    cout << absolute(i) << endl;
    return 0;
}
