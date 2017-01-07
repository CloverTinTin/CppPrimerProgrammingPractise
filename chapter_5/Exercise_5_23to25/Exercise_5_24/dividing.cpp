#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int i, j;

    cout << "Please input two numbers:\n";
    cin >> i >> j;
    if(j == 0)
	throw runtime_error("error: divisor is zero.");
    cout << i << " / " << j << " = "  << static_cast<double>(i) / j << endl;
    return 0;
}
