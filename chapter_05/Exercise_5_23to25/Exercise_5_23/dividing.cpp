#include <iostream>
using namespace std;

int main()
{
    int i, j;

    cout << "Please input two numbers:\n";
    cin >> i >> j;
    cout << i << " / " << j << " = "  << static_cast<double>(i) / j << endl;
    return 0;
}
